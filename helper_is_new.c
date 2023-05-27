#include "headers_shell.h"

/**
 * is_new - new alias or not.
 * @str: arg 1.
 * Return: 1 or 0.
 */
int is_new(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '=')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
