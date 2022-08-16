#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * main - interprets and executes Monty byte codes
 * @argc: the number of arguments passed
 * @argv: the array of arguments passed
 * Return: 0 upon success
 */

int main(int argc, char *argv[])
{
	char *line, *code;
	size_t len;
	unsigned int count;
	stack_t *temp, **stack;
	FILE *fd

	line = NULL;
	count = 1;
	len = 32;
	code = NULL;
	stack = NULL;
	fd = NULL;

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		open_error(argv[1]);
	}
	while ((getline(&line, &len, fd)) != -1)
	{
		code = strtok(line, " \t\n");
		if (code == NULL)
		{
			count = count + 1;
			continue;
		}
		arg.argument = strtok(NULL, " \t\n");
		_opcodes(code, &stack, count);
		count = count + 1;
	}
	free(line);

	while (*stack != NULL)
	{
		temporary = *stack;
		*stack = temporary->next;
		free(temporary);
	}
	close(fd);
	exit(0);
}
