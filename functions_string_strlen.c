#include "main.h"

/**
 * _strlen - Calculate the length of a string
 * @str: The string to calculate the length of
 *
 * Return: The length of the string.
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	while (str[len])
	{
		len++;
	}

	return (len);
}
