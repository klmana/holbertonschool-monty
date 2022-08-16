# Compiling for the hsh simple shell requirements are as follows;
# gcc -Wall -Werror -Wextra -pedantic -std=gnu90 *.c -o monty

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu90 -g
BETTY=betty
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./monty

TARGET=monty
SRC=	_opcodes.c \
	error_functions.c \
	mandatory_functions.c \
	monty_loop.c \
	_pint.c

SRC2=	*.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

betty:
	$(BETTY) $(SRC2)

val:
	$(VALGRIND) $(VFLAGS)
