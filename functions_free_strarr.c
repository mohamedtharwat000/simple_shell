#include "main.h"

/**
 * free_strarr - Frees memory allocated for an array of strings
 * @str: Pointer to the array of strings to be freed
 *
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
