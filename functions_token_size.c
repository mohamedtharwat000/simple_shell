#include "header_main.h"

/**
 * handle_token_size - returns number of delim
 * @str: user's command
 * @delm: delimeter
 * Return: number of tokens
 */
int handle_token_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delm)
		{
			num_delm++;
		}
		i++;
	}
	return (num_delm);
}
