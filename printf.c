#include "main.h"

/**
 * custom_printf - produces output according to a format
 * @format: the format string
 * @...: the variable arguments
 * Return: the number of characters printed
 */
int custom_printf(const char *format, ...)
{
	int char_counter = 0;
	va_list args;
	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	while (*format)
	{
		if (*format == '%')
	{
		format++;
		handle_custom_format(args, *format, &char_counter);
	}
		else
	{
		_put_custom_char(*format);
		char_counter++;
	}
		format++;
	}
	va_end(args);
	return (char_counter);
}
