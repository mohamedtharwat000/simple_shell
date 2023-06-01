#include "main.h"
/**
 * _strncpy - Copy a string up to a certain length
 * @dest: The destination buffer
 * @src: The source string
 * @n: The maximum number of characters to copy
 *
 * Return: Pointer to the destination buffer @dest.
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	if (!dest || !src)
	{
		return (NULL);
	}

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
