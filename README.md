# _printf

## Description
This project implements a simplified version of the C standard `printf` function. The function `_printf` formats and prints data to the standard output according to a specified format string.

## Features
- Handles the following conversion specifiers:
  - `%c` : Prints a character
  - `%s` : Prints a string
  - `%%` : Prints a percent sign
  - `%d` and `%i` : Prints integers
  - `%b` : Prints the binary representation of an unsigned integer

## Project Structure
- `main.h` : Header file containing function prototypes and necessary libraries.
- `_printf.c` : Core implementation of the `_printf` function.
- `helper_functions.c` : Helper functions for handling different format specifiers.
- `test/main.c` : Test cases to validate the functionality of `_printf`.

## Usage
### Compilation
Compile the project with the following command:
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
