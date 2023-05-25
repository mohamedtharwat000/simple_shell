#include "header_main.h"

/**
 * free_string_2d - free malloced arrays
 * @str: array of strings
 */
void free_string_2d(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
