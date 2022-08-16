#include "monty.h"

/**
 *push - add a new integer to the stack
 *@stack: doubly linked list representation of stack
 *@bricklayer_number: new number to store in the stack withinthestack_telement
 */

void push(stack_t **stack, unsigned int bricklayer_number)
{
	stack_t *new;
	char *arg = Arg.argument;
	int i = 0;
	int data;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", bricklayer_number);
		releasestack(stack);
		exit(EXIT_FAILURE);
	}
	while (arg[i] != '\0')
	{
		if (_isdigit(arg[i]) == 0 && arg[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", bricklayer_number);
			releasestack(stack);
			exit(EXIT_FAILURE);
		}
		i = i + 1;
		}
	data = atoi(arg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		releasestack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	*stack = new;
}

/**
 *pall - parses the stack and prints it from the top to the buttom
 *@stack: doubly linked list representation of a stack
 *@bricklayer_number: brick layer number from which thecontent shouldbe printed
 */

void pall(stack_t **stack, unsigned int bricklayer_number)
{
/* defines the existing stack */
	stack_t *existingStack;
/* stating the second parameter, bricklayer_number is unused in the function */
	(void)bricklayer_number;
/* case where the stack doesnt exists then take no action */
	if (stack == NULL || *stack == NULL)
		return;
/* defining the stack as existingStack to have atemporary stack to work with */
	existingStack = *stack;
/* case where it is not NULL then whil loop to go through the stack */
/* and print the content then go to the next block */
	while (existingStack != NULL)
	{
		printf("%d\n", existingStack->n);
		existingStack = existingStack->next;
	}
}


/**
 * add - adds the top two elements of the stack
 * @stack: doubly linked list representation of a stack
 * @bricklayer_number: brick layer number from which thecontent shouldbeprinted
*/

void add(stack_t **stack, unsigned int bricklayer_number)
{
	/* If the stack contains less than two elements, print error message */
	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", bricklayer_number);
		exit(EXIT_FAILURE);
	}
	/* adds the content of the 2 elements on top */
	(*stack)->next->n += (*stack)->n;
	/* removes the two elements of the top of the stack */
	/* then add the sum on top */
	pop(stack, bricklayer_number);
}


/**
 * nop - The opcode nop doesn’t do anything. ignores the command
 * @stack: doubly linked list representation of a stack
 * @bricklayer_number: brick layer number from whichthecontent shouldbe printed
 */

void nop(stack_t **stack, unsigned int bricklayer_number)
{
	(void) stack;
	(void) bricklayer_number;
}

/**
 * pint - prints the value at the top of the stack
 *@stack: doubly linked list representation of a stack
 *@bricklayer_number: brick layer number from which the
 * content is printed
 */

void pint(stack_t **stack, unsigned int bricklayer_number)
{

	if (stack == NULL || *stack == NULL)
	{
		pint_error(bricklayer_number);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - deletes the top stack element
 * @stack: a pointer to a doubly-linked list of elements
 * @bricklayer_number: the line at which the opcode occurs
 */

void pop(stack_t **stack, unsigned int bricklayer_number)
{
	stack_t *temporary;

	if (stack == NULL || *stack == NULL)
	{
		pop_error(bricklayer_number);
	}

	temporary = NULL;
	if (*stack != NULL)
	{
		temporary = *stack;
		*stack = (*stack)->next;
		free(temporary);
	}
}
/**
 * swap - swaps the top two stack elements
 * @stack: a pointer to a doubly-linked list of elements
 * @bricklayer_number: the line at which the opcode occurs
 * within the monty bytecode file
 */

void swap(stack_t **stack, unsigned int bricklayer_number)
{
	stack_t *temporary;
	int count;

	count = 0;
	temporary = *stack;
	while (temporary != NULL)
	{
		temporary = temporary->next;
		count = count + 1;
	}
	if (count < 2)
	{
		swap_error(bricklayer_number);
	}

	temporary = *stack;
	*stack = (*stack)->next;
	temporary->next = (*stack)->next;
	(*stack)->next = temporary;
	temporary->prev = *stack;
	(*stack)->prev = NULL;
}
