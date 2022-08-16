#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * open_error - exits after printing an error message
 * @arg: Name of file
 */

void open_error(char *arg)
{
	printf("Error: Can't open file %s\n", arg);
	exit(1);
}
