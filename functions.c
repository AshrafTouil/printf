#include "main.h"

/************************* PRINT CHARACTER *************************/

/**
 * print_character - Prints a character
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_character(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (handle_write_character(c, buffer, flags, width, precision, size));
}

/************************* WRITE HANDLE *************************/

/**
 * handle_write_character - Writes a character to the buffer
 * @c: Character to write
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters written
 */
int handle_write_character(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Character is stored at the left and padded at the buffer's right */
	int i = 0;
	char padding = ' ';

	/* Print a string */
}

/************************* PRINT STRING *************************/

/**
 * print_string - Prints a string
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	/* Unused variables */
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
	}

	/* Print a string */
}

/************************* WRITE HANDLE *************************/

/**
 * handle_write_character - Writes a character to the buffer
 * @c: Character to write
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters written
 */
int handle_write_character(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Character is stored at the left and padded at the buffer's right */
	int i = 0;
	char padding = ' ';

	if (precision >= 6)
		str = "      ";

	/* Calculate the length of the string */
	while (str[length] != '\0')
		length++;

	/* Apply precision */
	if (precision >= 0 && precision < length)
		length = precision;

	/* Apply width padding */
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/

/**
 * print_percent - Prints a percent sign
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Unused variables */
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	/* Print a percent sign */
	return (write(1, "%%", 1));
}
