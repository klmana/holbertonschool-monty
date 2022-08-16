#include "monty.h"

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
