#include "main.h"

/**
 * calculate_precision - Calcule la précision pour l'impression
 * @format: Chaîne formatée dans laquelle imprimer les arguments
 * @index: Liste des arguments à imprimer.
 * @args: Liste des arguments.
 *
 * Return: Précision.
 */
int calculate_precision(const char *format, int *index, va_list args)
{
	int curr_index = *index + 1;
	int precision = -1;

	if (format[curr_index] != '.')
		return (precision);

	precision = 0;

	for (curr_index += 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_digit(format[curr_index]))
		{
			precision *= 10;
			precision += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = curr_index - 1;

	return (precision);
}
