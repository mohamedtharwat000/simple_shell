#include "header_main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * Return: pointer to duplicated string in allocated memory
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (*(str + len))
	{
		len++;
	}
	len++;

	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < len)
	{
		*(duplicate_str + i) = *(str + i);
		i++;
	}

	return (duplicate_str);
}
