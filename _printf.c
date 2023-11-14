#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...) {
  int chars_written = 0;
  va_list args;
  va_start(args, format);

  while (*format) {
    if (*format != '%') {
      putc(*format, stdout);
      chars_written++;
    } else {
      switch (*++format) {
        case 'c':
          putc(va_arg(args, int), stdout);
          chars_written++;
          break;
        case 's':
          chars_written += puts(va_arg(args, char *));
          break;
        case '%':
          putc('%', stdout);
          chars_written++;
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
