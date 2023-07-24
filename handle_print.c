#include "main.h"

/**
 * handle_print - Imprime un argument en fonction de son type
 * @fmt: Chaîne formatée dans laquelle imprimer les arguments.
 * @list: Liste des arguments à imprimer.
 * @index: Index.
 * @buffer: Tampon pour gérer l'impression.
 * @flags: Calcule les drapeaux actifs.
 * @width: Obtenir la largeur.
 * @precision: Précision de spécification.
 * @size: Taille du spécificateur.
 * Return: 1 ou 2;
 */
int handle_print(const char *fmt, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*index] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		unknown_len += write(1, &fmt[*index], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
