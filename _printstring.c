#include "main.h"

/**
 * print_string - prints a string to the standard output
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int print_string(const char *str)
{
	int count = 0;

	if (str == NULL)
	{
		print_string("(null)");
		return (6);
	}

	while (*str != '\0')
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}
