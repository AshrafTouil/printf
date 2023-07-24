#include "main.h"

/**
 * calculate_size - Calcule la taille pour convertir l'argument
 * @format: Chaîne formatée dans laquelle imprimer les arguments
 * @index: Liste des arguments à imprimer.
 *
 * Return: Taille.
 */
int calculate_size(const char *format, int *index)
{
	int curr_index = *index + 1;
	int size = 0;

	if (format[curr_index] == 'l')
		size = S_LONG;
	else if (format[curr_index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*index = curr_index - 1;
	else
		*index = curr_index;

	return (size);
}
