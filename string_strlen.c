#include "headers_shell.h"

/**
 * _strlen - calculate the length.
 * @s: arg 1.
 * Return:The length.
 */
size_t _strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length])
	{
		length++;
	}
	return (length);
}
