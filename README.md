# Monty Byte Code Interpreter
> Interprets bytecodes as they appear in a Monty file, and executes accordingly

## Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

## Monty Byte Code Files
Files containing Monty byte codes usually have the ```.m``` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program$
```

## Installation and Operation
Clone this repository according to the following instruction:
```
git clone git@github.com:klmana/holbertonschool-monty.git
```
Compilation requires the following:
```
gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
```
Output is printed to stdout, and error messages are printed to stderr.

## Usage
```
./monty <monty_filename>
```
As aforementioned, Monty files have a ```.m``` suffix.

### An Example:
First, a Monty file:
```
user@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
```
And now, the result of correct usage with the interpreter:
```
user@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
user@ubuntu:~/monty$
```

## Technology Used To Write Interpreter
- Language: C programming language
- Operating System: Ubuntu 20.04
- Style: Betty

## Functions
* **push**
  * Usage: `push <int>`
  * Pushes an element to the stack.

* **pall**
  * Prints all values in the stack/queue, starting from the top.
  * Prints nothing if stack is empty

* **pint**
  * Prints the top value of the stack/queue.
  * Prints an error if stack is empty

* **pop**
  * Removes the top element of the stack/queue.
  * Prints an error if stack is empty

* **swap**
  * Swaps the top two elements of the stack/queue.
  * Prints an error if stack is less than 2 elements

* **nop**
  * Does not do anything.

## Authors
Karren Nonyta | [Github - klmana](https://github.com/klmana)
Hamish Ross | [Github - Gotmished](https://github.com/Gotmished)