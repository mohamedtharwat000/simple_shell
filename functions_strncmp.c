#include "main.h"

/**
 * _strncmp - Compare two strings up to a given number of characters
 * @str1: The first string to compare
 * @str2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * This function compares the first @n characters of the
 * strings @str1 and @str2.
 * If the characters are equal, the comparison continues until the end of the
 * strings or until @n characters have been compared. If a difference is found
 * before reaching @n characters, the function returns a negative value. If the
 * first @n characters are equal, the function returns 0.
 *
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if the first @n characters are equal, otherwise a negative value.
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
