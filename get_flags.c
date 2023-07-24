#include "main.h"

/**
 * calculate_flags - Calcule les drapeaux actifs
 * @format: Chaîne formatée dans laquelle imprimer les arguments
 * @index: Prend un paramètre.
 * Return: Drapeaux :
 */
int calculate_flags(const char *format, int *index)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int j, curr_index;
	int flags = 0;
	const char FLAG_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_index = *index + 1; format[curr_index] != '\0'; curr_index++)
	{
		for (j = 0; FLAG_CHARACTERS[j] != '\0'; j++)
			if (format[curr_index] == FLAG_CHARACTERS[j])
			{
				flags |= FLAG_VALUES[j];
				break;
			}

		if (FLAG_CHARACTERS[j] == 0)
			break;
	}

	*index = curr_index - 1;

	return (flags);
}
