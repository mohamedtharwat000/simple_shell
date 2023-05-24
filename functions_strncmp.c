#include "main.h"
/**
 * _strncmp - Compare two strings up to a certain length
 * @str1: The first string to compare
 * @str2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * Return: on success (if str1 == str2) 0.
 * otherwise -1
 */
ssize_t _strncmp(char *str1, char *str2, size_t n)
{
	size_t i;

	if (!str1 || !str2)
	{
		return (-1);
	}

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
	}

	return (0);
}
