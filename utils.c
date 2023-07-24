#include "main.h"

/**
 * is_char_printable - Évalue si un caractère est imprimable
 * @c: Caractère à évaluer.
 *
 * Retourne: 1 si c est imprimable, 0 sinon
 */
int is_char_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hex_code - Ajoute le code ASCII en hexadécimal au tampon
 * @buffer: Tableau de caractères.
 * @index: Index à partir duquel commencer à ajouter.
 * @ascii_code: Code ASCII.
 * Retourne: Toujours 3
 */
int append_hex_code(char ascii_code, char buffer[], int index)
{
	char map_to[] = "0123456789ABCDEF";
	/* Le code hexadécimal est toujours composé de 2 chiffres */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = map_to[ascii_code / 16];
	buffer[index] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_char_digit - Vérifie si un caractère est un chiffre
 * @c: Caractère à évaluer
 *
 * Retourne: 1 si c est un chiffre, 0 sinon
 */
int is_char_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_number_with_size - Effectue un cast d'un nombre vers le type spécifié
 * @num: Nombre à caster.
 * @size: Entier indiquant le type vers lequel effectuer le cast.
 *
 * Retourne: Valeur castée de num
 */
long int convert_number_with_size(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_unsigned_number_with_size - Effectue un cast d'un nombre non signé vers le type spécifié
 * @num: Nombre à caster
 * @size: Entier indiquant le type vers lequel effectuer le cast
 *
 * Retourne: Valeur castée de num
 */
long int convert_unsigned_number_with_size(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
