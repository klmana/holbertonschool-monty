#include "monty.h"

/**
 * nop - The opcode nop doesn’t do anything. Ignores the command
 * @stack: doubly linked list representation of a stack
 * @monty_line: the line in the monty bytecode file
 * at which the relevant opcode occurs
 */

void nop(stack_t **stack, unsigned int monty_line)
{
	(void) stack;
	(void) monty_line;
}

/**
 * pint - prints the value at the top of the stack
 * @stack: doubly linked list representation of a stack
 * @monty_line: the line in the monty bytecode file
 * at which the relevant opcode occurs
 */

void pint(stack_t **stack, unsigned int monty_line)
{

	if (stack == NULL || *stack == NULL)
	{
		pint_error(monty_line);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - deletes the top stack element
 * @stack: a pointer to a doubly-linked list of elements
 * @monty_line: the line in the monty bytecode file
 * at which the relevant opcode occurs
 */

void pop(stack_t **stack, unsigned int monty_line)
{
	stack_t *temporary;

	if (stack == NULL || *stack == NULL)
	{
		pop_error(monty_line);
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
 * @monty_line: the line in the monty bytecode file
 * at which the relevant opcode occurs
 */

void swap(stack_t **stack, unsigned int monty_line)
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
		swap_error(monty_line);
	}

	temporary = *stack;
	*stack = (*stack)->next;
	temporary->next = (*stack)->next;
	(*stack)->next = temporary;
	temporary->prev = *stack;
	(*stack)->prev = NULL;
}
