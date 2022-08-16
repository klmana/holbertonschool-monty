#include "monty.h"

/**
 *push - add a new integer to the stack
 *@stack: doubly linked list representation of stack
 *@number: new number to store in the stack within the stack_t element
 */

void push(stack_t **stack, unsigned int number)
{
/* Define the stack_t as a new item in the double linked list */
	stack_t *new;
	char *arg = Arg.argument;
	int i = 0;
	int data;

/* Case where the syntax is not correct then display error message and exit the process */
        if (arg == NULL)
        {
                fprintf(stderr, "L%d: usage: push integer\n", number);
                releasestack(stack);
                exit(EXIT_FAILURE);
        }
/* Case where there is an entry which is not an integer in the argument then display error message and exit the process */
	while(arg[i] != '\0')
	{
		if (_isdigit(arg[i]) == 0 && arg[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", number);
			releasestack(stack);
			exit(EXIT_FAILURE);
		}
		i = i + 1;
	}

	data = atoi(arg);
/* Prepare space for the new item called new */
        new = malloc(sizeof(stack_t));
/* Case where there is not enough space in memory then display error message and exit the proces\
s */
        if (new == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                releasestack(stack);
                exit(EXIT_FAILURE);
        }

/* Normal case where the new stack element will host the number (integer) to be added */
/* new element in stack is becaming the number then defines the previouse element */
/* as empty (NULL) then includes the new element in the overall stack */
	new->n = data;
	new->prev = NULL;
	new->next = *stack;
/* So if the stack exists then include the new element to it */
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
 *@bricklayer_number: brick layer number from which the content shouldbe printed
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
/* defining the stack as existingStack to have a temporary stack to work with */
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
 * @bricklayer_number: brick layer number from which the content shouldbe printed 
*/

void add(stack_t **stack, unsigned int bricklayer_number)
{
	unsigned int sum;

	/* If the stack contains less than two elements, print the error message */
	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", bricklayer_number);
		exit(EXIT_FAILURE);
	}
	/* adds the content of the 2 elements on top */
	sum = (*stack)->n + (*stack)->next->n;
	/* removes the two elements of the top of the stack */
	/* then add the sum on top */
	pop(stack, 0);
	pop(stack, 0);
	push(stack, sum);
}


/** 
 * nop - The opcode nop doesn’t do anything. ignores the command
 * @stack: doubly linked list representation of a stack
 * @bricklayer_number: brick layer number from which the content shouldbe printed
*/

void nop(stack_t **stack, unsigned int bricklayer_number)
{
	(void) stack;
	(void) bricklayer_number;
}
