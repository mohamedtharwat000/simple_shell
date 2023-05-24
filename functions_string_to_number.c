#include "main.h"
/**
 * string_to_number - Convert a string to an integer number
 * @str: The string to convert
 *
 * Return: The converted integer number, or 0 if the conversion fails
 */
int string_to_number(char *str)
{
	int number = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number = number * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			return (0);
		}
	}

	return (number * sign);
}
