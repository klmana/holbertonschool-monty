#include <string.h>
#include "monty.h"

/**
 * _opcodes - executes each line of a Monty file
 * @code: the name of the opcode to check and use
 * @stack: the stack on which the opcode will be executed
 * @count: the line number in the Monty file containing an opcode
 */

void _opcodes(char *code, stack_t **stack, unsigned int count)
{
	int i;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, code) == 0)
		{
			opcodes[i].f(stack, count);
			return;
		}
		i = i + 1;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, code);
	exit(EXIT_FAILURE);
}
