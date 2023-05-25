#include "header_main.h"


/**
 * token_size - returns number of delim
 * @str: user's command typed into shell
 * @delm: delimeter
 * Return: number of delims
 */
int token_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
		{
			num_delm++;
		}
		if ((str[i] == delm) && (str[i + 1] == '\0'))
		{
			num_delm--;
		}
		i++;
	}
	return (num_delm);
}
