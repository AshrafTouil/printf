#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * write_char_handler - Imprime un caractère
 * @c: Caractère à imprimer.
 * @buffer: Tampon pour gérer l'impression.
 * @flags: Drapeaux actifs.
 * @width: Largeur.
 * @precision: Précision de spécification.
 * @size: Taille du spécificateur.
 *
 * Retourne: Nombre de caractères imprimés.
 */
int write_char_handler(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* Le caractère est stocké à gauche et l'espacement à droite du tampon */
	int i = 0;
	char padding_char = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padding_char = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padding_char;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Imprime un nombre
 * @is_negative: Liste des arguments
 * @index: Index du caractère.
 * @buffer: Tampon pour gérer l'impression.
 * @flags: Drapeaux actifs.
 * @width: Largeur.
 * @precision: Précision de spécification.
 * @size: Taille du spécificateur.
 *
 * Retourne: Nombre de caractères imprimés.
 */
int write_number(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padding_char = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';

	return (write_num(index, buffer, flags, width, precision,
		length, padding_char, extra_char));
}

/**
 * write_num - Écrit un nombre en utilisant un tampon
 * @index: Index à partir duquel le nombre commence dans le tampon.
 * @buffer: Tampon
 * @flags: Drapeaux
 * @width: Largeur
 * @precision: Précision de spécification
 * @length: Longueur du nombre
 * @padding_char: Caractère d'espacement
 * @extra_char: Caractère supplémentaire
 *
 * Retourne: Nombre de caractères imprimés.
 */
int write_num(int index, char buffer[],
	int flags, int width, int precision,
	int length, char padding_char, char extra_char)
{
	int i, padding_start = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0); /* printf(".0d", 0) aucun caractère n'est imprimé */
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padding_char = ' '; /* La largeur est affichée avec un espacement ' ' */
	if (precision > 0 && precision < length)
		padding_char = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padding_char;
		buffer[i] = '\0';
		if (flags & F_MINUS && padding_char == ' ')/* Affecter un caractère supplémentaire à gauche du tampon */
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padding_char == ' ')/* Caractère supplémentaire à gauche du tampon */
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padding_char == '0')/* Caractère supplémentaire à gauche du remplissage */
		{
			if (extra_char)
		}
	}
