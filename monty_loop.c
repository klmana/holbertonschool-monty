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
	stack_t *stack;
	FILE *fd;

	line = NULL;
	count = 1;
	len = 0;
	code = NULL;
	stack = NULL;
	fd = NULL;

	if (argc != 2)
	{
		arg_error();
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		open_error(argv[1]);
	}
	while ((getline(&line, &len, fd)) != -1)
	{
		if (*line == '\n')
		{
			count = count + 1;
			continue;
		}
		code = strtok(line, " \t\n");
		if (code == NULL)
		{
			count = count + 1;
			continue;
		}
		Arg.argument = strtok(NULL, " \t\n");
		_opcodes(code, &stack, count);
		count = count + 1;
	}
	free(line);
	releasestack(&stack);
	fclose(fd);
	return(0);
}


/**
 * releasestack - receives a stack as parameter, create temporary element then frees the space	
 * @stack: doubly linked list representation of a stack
 */

void releasestack(stack_t **stack)
{
	stack_t *existingStack;

	while ((*stack) != NULL)
	{
		existingStack = (*stack);
		(*stack) = (*stack)->next;
		free(existingStack);
	}
}

/**
 *_isdigit - function that checks for a digit (0 through 9)
 *@c: returns 1 if c is digit
 *Return: always 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
