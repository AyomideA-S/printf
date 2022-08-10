#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>

/**
 * struct print - Structure for printing various types of ASCII characters
 * @format: format specifier
 * @p: print function
 */
typedef struct print
{
	char *format;
	int (*p)(va_list);
} print_format;

int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list c);
int print_s(va_list s);

#endif  /* _MAIN_H */