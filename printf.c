#include "main.h"
/**
 * _printf - produces output according to a format
 * @format:
 * @...:
 * Return: counter
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	va_list arg;

	va_start(arg, format);

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
			handle_format(arg, *format, &counter);
		}
		else
		{
			_putchar(*format);
			counter++;
		}
		format++;
	}
	va_end(arg);
	return (counter);
}
