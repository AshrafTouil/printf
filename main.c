#include "main.h"
#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	int len, len_p;
	int n = 10;

	_printf("%S", "No special.");
	printf("\n");
	_printf("hi\n");
	printf("hi\n");
	_printf("%S", "\n");
	printf("\n");
	_printf("%S", "\x01\x02\x03\x04");
	printf("\n");
	_printf("could you print non-print?\n%S\nthanks!\n", "sure:\x1F\x7F\n");
	_printf("");
	_printf("...what say?\n- %S\n- that.\n", "");
	len = printf("1 ~%%h%s world %c\n", "hello", 'M');
	printf("\n");
	len_p = _printf("1 ~%%h%s world %c\n", "hello", 'M');
	printf("\nlen: %d len_p: %d\n", len, len_p);
	len = _printf("2 ~%X\n", -2);
	len_p = printf("2 ~%X\n", -2);
	printf("\nlen: %d len_p: %d\n", len, len_p);
	len = _printf("3 ~%X\n", -1024);
	len_p = printf("3 ~%X\n", -1024);
	printf("\nlen: %d len_p: %d\n", len, len_p);
	len = _printf("4 ~%X\n", UINT_MAX);
	len_p = printf("4 ~%X\n", UINT_MAX);
	printf("\nlen: %d len_p: %d\n", len, len_p);
	len = _printf("5 ~%X\n", INT_MAX);
	len_p = printf("5 ~%X\n", INT_MAX);
	printf("\nlen: %d len_p: %d\n", len, len_p);
	len = _printf("%p\n", &num);
	len_p = printf("%p\n", &num);
	printf("%d\n%d\n", len, len_p);
	return (0);
}
