#include "main.h"

/**
 * print_c - A function that prints an ASCII character of type char
 * @c: Character to be printed
 * Return: 1 (Success)
 */
int print_c(va_list c)
{
	char character = (char)va_arg(c, int);

	_putchar(character);
	return (1);
}