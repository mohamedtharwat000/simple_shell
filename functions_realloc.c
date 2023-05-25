#include "header_main.h"

/**
 * _realloc - reallocate memory
 * @ptr: pointer to the memory
 * @old_size: size previously allocated
 * @new_size: new size to reallocate
 * Return: pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
		{
			return (NULL);
		}
		else
		{
			return (p);
		}
	}

	p = malloc(new_size);
	if (p == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < old_size && i < new_size; i++)
	{
		*((char *)p + i) = *((char *)ptr + i);
	}
	free(ptr);

	return (p);
}
