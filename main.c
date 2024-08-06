#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Mimics the printf function, supporting %b for binary conversion
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c;
    
    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'b')  /* Handle binary format */
            {
                unsigned int num = va_arg(args, unsigned int);
                int bin[32], j = 0;

                while (num > 0)
                {
                    bin[j++] = num % 2;
                    num /= 2;
                }
                while (--j >= 0)
                    count += write(1, &"01"[bin[j]], 1);
            }
            else if (format[i] == '%')
            {
                count += write(1, "%", 1);
            }
            else
            {
                c = format[i];
                count += write(1, &c, 1);
            }
        }
        else
        {
            c = format[i];
            count += write(1, &c, 1);
        }
        i++;
    }
    
    va_end(args);
    return (count);
}
