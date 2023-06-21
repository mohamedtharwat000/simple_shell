#include "main.h"

/**
 * _spaces_ignore - Ignore spaces in a string
 * @str: The string to process
 *
 * Return: 0 if the string contains only spaces, -1 otherwise
 */
ssize_t _spaces_ignore(char *str)
{
	size_t i = 0;

	while (str[i])
	{
		if (str[i++] != ' ')
		{
			return (-1);
		}
	}

	return (0);
}
