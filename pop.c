#include "monty.h"

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
