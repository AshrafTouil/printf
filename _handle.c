#include "main.h"
/**
 * process_format_specifier - handles different specifiers
 * @printCounter: the printCounter
 * @specifier: the specifier
 * @arg: argument
 */
void process_format_specifier(va_list arg, char specifier, int *printCounter)
{
	switch (specifier)
	{
		case 'c':
				(*printCounter) += _putchar(va_arg(arg, int));
				break;
		case 's':
				(*printCounter) += put_string(va_arg(arg, char *));
				break;
		case '%':
				(*printCounter) += _putchar('%');
				break;
		case 'i':
		case 'd':
				(*printCounter) += print_number(va_arg(arg, int));
				break;
		case 'b':
				(*printCounter) += print_binary(va_arg(arg, unsigned int));
				break;
		default:
				_putchar('%');
				_putchar(specifier);
				(*printCounter) += 2;
				break;
	}
}

