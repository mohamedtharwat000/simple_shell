#include "main.h"


/**
 * _memset - fill memory with NULL
 * @ptr: The pointer.
 * @size: The Pointer size.
 *
 * Return: void.
 *
 */

void _memset(char *ptr, size_t size)
{
	size_t i;


	for (i = 0; i < size; i++)
	{
		ptr[i] = '\0';
	}
}
