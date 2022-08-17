#include <string.h>
#include "monty.h"

/**
 * _opcodes - executes each line of a Monty file
 * @code: the name of the opcode to check and use
 * @stack: the stack on which the opcode will be executed
 * @monty_line: the line number in the monty bytecode file
 * containing the relevant opcode
 */

void _opcodes(char *code, stack_t **stack, unsigned int monty_line)
{
	int i;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, code) == 0)
		{
			opcodes[i].f(stack, monty_line);
			return;
		}
		i = i + 1;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", monty_line, code);
	exit(EXIT_FAILURE);
}
