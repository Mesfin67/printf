#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int chars_written = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            putc(*format, stdout);
            chars_written++;
        }
        else
        {
            switch (*++format)
            {
            case 'd':
                chars_written += fprintf(stdout, "%d", va_arg(args, int));
                break;
            case 'i':
                chars_written += fprintf(stdout, "%i", va_arg(args, int));
                break;
            default:
                break;
            }
        }
        format++;
    }

    va_end(args);
    return chars_written;
}

