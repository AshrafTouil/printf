#include <unistd.h>

/**
 * write_character - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_character(char c)
{
	return (write(1, &c, 1));
}
