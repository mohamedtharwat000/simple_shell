#include "main.h"

/**
 * _strncpy - Copy a string up to a given number of characters
 * @dest: The destination buffer to copy the string into
 * @src: The source string to be copied
 * @n: The maximum number of characters to copy
 *
 * This function copies at most @n characters from the string @src into the
 * buffer @dest. If the length of @src is less than @n, the remaining characters
 * in @dest are filled with null bytes. If @src is longer than @n, the resulting
 * @dest string will not be null-terminated. The @dest and @src strings must be
 * null-terminated and valid pointers.
 *
 * @dest: The destination buffer to copy the string into.
 * @src: The source string to be copied.
 * @n: The maximum number of characters to copy.
 *
 * Return: Pointer to the destination string @dest.
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
