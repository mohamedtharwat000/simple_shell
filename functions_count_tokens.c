#include "main.h"

/**
 * count_tokens - Count the number of tokens in a string using a delimiter
 * @str: The string to be counted
 * @delim: The delimiter used to count the tokens
 *
 * Return: The count of tokens found in the string.
 */
size_t count_tokens(char *str, char *delim)
{
	size_t i = 0, count = 0, dlen = _strlen(delim);

	if (_strlen(str) == 0)
	{
		return (0);
	}
	if (_strlen(delim) == 0)
	{
		return (_strlen(str));
	}
	while (str[i])
	{
		if (_strncmp(&str[i], delim, dlen) == 0)
		{
			if (i != 0)
			{
				count++;
			}
			while (_strncmp(&str[i], delim, dlen) == 0)
			{
				i += dlen;
			}
			if (_strncmp(&str[i - dlen], delim, dlen) == 0)
			{
				continue;
			}
		}
		i++;
	}
	if (str[i] == '\0')
	{
		if (_strncmp(&str[i - dlen], delim, dlen) != 0)
		{
			count++;
		}
	}
	return (count);
}
