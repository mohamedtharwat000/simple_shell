#include "main.h"

/**
 * free_strarr - Frees memory allocated for an array of strings
 * @arr: Pointer to the array of strings to be freed
 *
 */
void free_strarr(char **arr)
{
	size_t i = 0;

	if (arr == NULL)
	{
		return;
	}

	for (; arr[i]; i++)
	{
		free(arr[i]);
	}

	free(arr);
}
