#include "headers_shell.h"

/**
 * is_num - is number.
 * @str: arg 1.
 * Return: 1 if is number.
 */
int	is_num(char *str)
{
	int i = 0;

	if (str[0] && (str[0] == '-' || str[0] == '+'))
	{
		i++;
	}
	if (!str[i])
	{
		return (0);
	}
	while (str[i] && str[i] == '0')
	{
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

