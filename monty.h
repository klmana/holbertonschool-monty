#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arg - argument for the current opcode
 * @argument: the arguments of the string
 */
typedef struct arg
{
	char *argument;
} arg;
arg Arg;

void push(stack_t **stack, unsigned int);
void pall(stack_t **stack, unsigned int);
void pint(stack_t **stack, unsigned int bricklayer_number);
void pop(stack_t **stack, unsigned int bricklayer_number);
void swap(stack_t **stack, unsigned int bricklayer_number);
void add(stack_t **stack, unsigned int bricklayer_number);
void nop(stack_t **stack, unsigned int bricklayer_number);
void _opcodes(char *code, stack_t **stack, unsigned int count);
void arg_error(void);
void open_error(char *arg);
void pint_error(unsigned int bricklayer_number);
void pop_error(unsigned int bricklayer_number);
void releasestack(stack_t **stack);
int _isdigit(int c);

#endif
