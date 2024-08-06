#include "main.h"

/**
 * _printf - Mimics the C standard printf function
 * @format: format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    int (*f)(va_list);

    if (!format)
        return (-1);

    va_start(args, format);
    
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                return (-1);

            f = get_function(format[i]);
            if (f)
                count += f(args);
            else
            {
                count += write(1, "%", 1);
                count += write(1, &format[i], 1);
            }
        }
        else
            count += write(1, &format[i], 1);
        i++;
    }
    va_end(args);
    return (count);
}
