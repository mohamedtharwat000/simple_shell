#include "main.h"

/**
 * free_strarr - Frees memory allocated for an array of strings
 * @str: Pointer to the array of strings to be freed
 *
 * This function frees the memory allocated for each string in the array and
 * then frees the memory allocated for the array itself.
 *
 * @str must be a NULL-terminated array of strings, where the last element
 * is a NULL pointer.
 *
 * @str should have been previously allocated using dynamic memory allocation
 * functions, such as malloc or calloc.
 */
void free_strarr(char **str)
{
	size_t i;

	for (i = 0; str[i]; i++)
	{
		free(str[i]);
	}
	free(str);
}
