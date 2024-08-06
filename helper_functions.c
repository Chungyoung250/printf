#include "main.h"

static int print_number(unsigned int n, int base, int uppercase);
static void reverse_string(char *str);

/* Print functions */

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

/**
 * print_unsigned - Print an unsigned integer
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    return print_number(n, 10, 0);
}

/**
 * print_octal - Print an octal number
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    return print_number(n, 8, 0);
}

/**
 * print_hex - Print a hexadecimal number
 * @args: Argument list
 * @uppercase: Whether to use uppercase letters
 *
 * Return: Number of characters printed
 */
static int print_hex(va_list args, int uppercase)
{
    unsigned int n = va_arg(args, unsigned int);
    return print_number(n, 16, uppercase);
}

/**
 * print_pointer - Print a pointer address
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    char buffer[19];
    int len = 0;

    if (!ptr)
        return (write(1, "(nil)", 5));

    // Add "0x" prefix
    len += write(1, "0x", 2);
    len += print_hex(va_arg(args, unsigned long), 0);

    return (len);
}

/**
 * print_string_custom - Print a string with non-printable characters
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_string_custom(va_list args)
{
    char *str = va_arg(args, char *);
    char buffer[1024];
    int len = 0, i;

    if (!str)
        str = "(null)";

    for (i = 0; str[i]; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            len += write(1, "\\x", 2);
            len += write(1, &str[i], 1);
        }
        else
        {
            buffer[len++] = str[i];
        }
    }

    return (write(1, buffer, len));
}

/**
 * print_reverse - Print a reversed string
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_reverse(va_list args)
{
    char *str = va_arg(args, char *);
    char buffer[1024];
    int len = 0, i;

    if (!str)
        str = "(null)";

    for (i = 0; str[i]; i++)
        len++;

    for (i = len - 1; i >= 0; i--)
        buffer[len - i - 1] = str[i];

    return (write(1, buffer, len));
}

/**
 * print_rot13 - Print a ROT13 encoded string
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_rot13(va_list args)
{
    char *str = va_arg(args, char *);
    char buffer[1024];
    int len = 0, i;

    if (!str)
        str = "(null)";

    for (i = 0; str[i]; i++)
    {
        char c = str[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            c = (c - (c >= 'a' ? 'a' : 'A') + 13) % 26;
            c += (c >= 'a' ? 'a' : 'A');
        }
        buffer[len++] = c;
    }

    return (write(1, buffer, len));
}

/* Helper functions */

/**
 * print_number - Print an integer in a given base
 * @n: Number to print
 * @base: Base to use for printing (10 for decimal, 8 for octal, 16 for hex)
 * @uppercase: Use uppercase letters for hex
 *
 * Return: Number of characters printed
 */
static int print_number(unsigned int n, int base, int uppercase)
{
    char buffer[33];
    char digits[] = "0123456789abcdef";
    int len = 0;
    if (uppercase)
        digits[10] = 'A'; digits[11] = 'B'; digits[12] = 'C'; digits[13] = 'D'; digits[14] = 'E'; digits[15] = 'F';

    if (n == 0)
        buffer[len++] = '0';

    while (n > 0)
    {
        buffer[len++] = digits[n % base];
        n /= base;
    }

    reverse_string(buffer);
    return (write(1, buffer, len));
}

/**
 * reverse_string - Reverse a string in place
 * @str: String to reverse
 */
static void reverse_string(char *str)
{
    int len = 0;
    char temp;
    while (str[len])
        len++;
    for (int i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
