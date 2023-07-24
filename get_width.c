#include "main.h"

/**
 * calculate_width - Calcule la largeur pour l'impression
 * @format: Chaîne formatée dans laquelle imprimer les arguments.
 * @index: Liste des arguments à imprimer.
 * @args: Liste des arguments.
 *
 * Return: Largeur.
 */
int calculate_width(const char *format, int *index, va_list args)
{
	int curr_index;
	int width = 0;

	for (curr_index = *index + 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_digit(format[curr_index]))
		{
			width *= 10;
			width += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = curr_index - 1;

	return (width);
}
