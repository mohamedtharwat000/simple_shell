

#include "header_main.h"

/**
 * token_strlen - returns token's string length
 * @str: token
 * @pos: index position
 * @delm: delimeter
 * Return: length
 */
int token_strlen(char *str, int pos, char delm)
{
	int len = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		len++;
	}
	return (len);
}
