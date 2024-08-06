#include "main.h"

/**
 * print_char - Print a character
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - Print a string
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (!str)
        str = "(null)";
    while (str[len])
        len++;
    return (write(1, str, len));
}

/**
 * print_percent - Print a percent sign
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_percent(va_list args)
{
    (void)args;
    return (write(1, "%", 1));
}

/**
 * print_int - Print an integer
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    char buffer[11];
    int len = 0;

    itoa(n, buffer, 10);
    while (buffer[len])
        len++;
    return (write(1, buffer, len));
}

/**
 * print_binary - Print a number in binary format
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[33];
    int len = 0;

    itoa(n, buffer, 2);
    while (buffer[len])
        len++;
    return (write(1, buffer, len));
}
