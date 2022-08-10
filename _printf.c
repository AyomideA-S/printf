#include "main.h"
#include <stdarg.h>

/**
 * check_format - Checks for a valid format specifier
 * @format: Format specifier
 * Return: Pointer to corresponding function else NULL
 */
int (*check_format(const char *format))(va_list)
{
	int i;
	print_format p[] = {
		{"c", print_c},
		{"s", print_s},
		{NULL, NULL}
	};

	for (i = 0; p[i].format != NULL; i++)
	{
		if (*(p[i].format) == *format)
			break;
	}
	return (p[i].format);
}

/**
 * _printf - Function for format printing
 * @format: List of arguments to be printed
 * Return: Number of characters to be printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, counter = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			counter++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				counter++;
				i += 2;
				continue;
			}
			else
			{
				f = check_format(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 2;
				counter += f(ap);
				continue;
			}
		}
		i++;
	}
	va_end(ap);
	return (counter);
}