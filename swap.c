#include "monty.h"

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
