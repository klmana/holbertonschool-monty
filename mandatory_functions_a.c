#include "monty.h"

/**
 * push - add a new integer to the stack
 * @stack: doubly linked list representation of stack
 * @monty_line: the line in the monty bytecode file
 * at which the relevant opcode occurs
 */

void push(stack_t **stack, unsigned int monty_line)
{
	stack_t *new;
	char *arg = g_Arg.argument;
	int i = 0;
	int data;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", monty_line);
		releasestack(stack);
		exit(EXIT_FAILURE);
	}
	while (arg[i] != '\0')
	{
		if (_isdigit(arg[i]) == 0 && arg[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", monty_line);
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
 * pall - parses the stack and prints it from the top to the buttom
 * @stack: doubly linked list representation of a stack
 * @monty_line: the line in the monty bytecode file
 * at which the relevant opcode occurs
 */

void pall(stack_t **stack, unsigned int monty_line)
{
/* defines the existing stack */
	stack_t *existingStack;
/* stating the second parameter, monty_line is unused in the function */
	(void)monty_line;
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
 * @monty_line: the line in the monty bytecode file
 * at which the relevant opcode occurs
 */

void add(stack_t **stack, unsigned int monty_line)
{
	/* If the stack contains less than two elements, print error message */
	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", monty_line);
		exit(EXIT_FAILURE);
	}
	/* adds the content of the 2 elements on top */
	(*stack)->next->n += (*stack)->n;
	/* removes the two elements of the top of the stack */
	/* then add the sum on top */
	pop(stack, monty_line);
}
