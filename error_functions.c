#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 *arg_error - exits after printing an error message
 */
void arg_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_error - exits after printing an error message
 * @arg: Name of file
 */

void open_error(char *arg)
{
	fprintf(stderr, "Error: Can't open file %s\n", arg);
	exit(EXIT_FAILURE);
}

/**
 * pint_error - exits after printing an error message
 * @monty_line: the line at which the opcode occurs
 * in the Monty bytecode file
 */

void pint_error(unsigned int monty_line)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", monty_line);
	exit(1);
}

/**
 * pop_error - exits after printing an error message
 * @monty_line: the line at which the opcode occurs
 * in the Monty bytecode file
 */

void pop_error(unsigned int monty_line)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", monty_line);
	exit(1);
}

/**
 * swap_error - exits after printing an error message
 * @monty_line: the line at which the opcode occurs
 * in the Monty bytecode file
 **/

void swap_error(unsigned int monty_line)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", monty_line);
	exit(1);
}
