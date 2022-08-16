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
