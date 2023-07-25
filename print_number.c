#include "main.h"

/**
 * print_number - prints the number
 * @n: the number
 * Return: counter
 */

int print_number(int n)
{
	int numCounter  = 0;

	if (n == -2147483648)
		return (put_string("-2147483648"));
	if (n < 0)
	{
		_putchar('-');
		n = -n;
		numCounter++;
	}

	if (n < 10)
	{
		_putchar('0' + n);
		numCounter++;
	}
	else
	{
		numCounter  += print_number(n / 10);
		_putchar('0' + n % 10);
		numCounter++;
	}
	return (numCounter);
}
