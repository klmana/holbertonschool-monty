#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * _open - opens a file whose name is based upon user input
 * @arg: User input strings
 */

void _open(char *arg[])
{
	int fd;

	fd = open(arg[1], O_RDONLY);
	if (fd == -1 || argv[1] == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(1);
	}
}
