#include "main.h"
/**
 * _strncat - Concatenate two strings up to a certain length
 * @dest: The destination buffer
 * @src: The source string
 * @n: The maximum number of characters to concatenate
 *
 * Return: Pointer to the destination buffer @dest.
 */
char *_strncat(char *dest, char *src, size_t n)
{
	size_t i = 0, dest_len = _strlen(dest);

	if (!dest || !src)
	{
		return (NULL);
	}

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len] = src[i];
		dest_len++;
	}

	dest[dest_len] = '\0';

	return (dest);
}
