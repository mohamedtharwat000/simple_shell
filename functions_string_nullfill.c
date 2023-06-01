#include "main.h"

/**
 * null_fill - Fill a block of memory with null characters
 * @mem: Pointer to the memory block
 * @size: Size of the memory block
 *
 * This function fills a block of memory with null characters.
 */
void null_fill(char *mem, size_t size)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		mem[i] = '\0';
	}
}
