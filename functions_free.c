#include "main.h"


/**
 * _free - Frees memory allocated for a pointer and sets it to NULL
 * @str: Pointer to a pointer to be freed
 */
void _free(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}


/**
 * _free_arr - Frees memory allocated for an array of pointers
 * and sets them to NULL
 * @arr: Pointer to a pointer array to be freed
 */
void _free_arr(char ***arr)
{
	size_t i = 0;

	if (arr != NULL && *arr != NULL)
	{
		for (i = 0; (*arr)[i] != NULL; i++)
		{
			_free(&((*arr)[i]));
		}
		free(*arr);
		*arr = NULL;
	}
}



