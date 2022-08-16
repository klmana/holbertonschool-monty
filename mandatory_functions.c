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
/* Prepare space for the new item called new */
	new = malloc(sizeof(stack_t));
/* Case where there is not enough space in memory then display error message and exit the process */
	if (new == NULL || arg == NULL)
	{
		fprintf(stderr, "Erorr: malloc failed\n");
		releasestack(stack);
		exit(EXIT_FAILURE);
	}
/* Normal case where the new stack element will host the number (integer) to be added */
/* new element in stack is becaming the number then defines the previouse element */
/* as empty (NULL) then includes the new element in the overall stack */
	new->n = number;
	new->prev = NULL;
	new->next = *stack;
/* So if the stack exists then include the new element to it */
	if (*stack != NULL)
		(*stack)->prev = new;
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
/* defining the stack as existingStack to have a temporary stack to work with */
	existingStack = *stack;
/* case where the stack doesnt exists then take no action */
	if (existingStack == NULL)
		return;
/* case where it is not NULL then whil loop to go through the stack */
/* and print the content then go to the next block */
	while (existingStack != NULL)
	{
		printf("%d\n", existingStack->n);
		existingStack = existingStack->next;
	}
}
