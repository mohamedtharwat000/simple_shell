#include "main.h"
/**
 * numtostr - Convert an integer to a string
 * @num: The integer to convert
 *
 * Return: A pointer to the string, or NULL if memory allocation fails.
 *
 */
char *numtostr(int num)
{
	int i = 0, length = 0, temp = num;
	char *str = NULL;

	while (temp != 0)
	{
		length++;
		temp /= 10;
	}

	str = (char *)malloc((length + 1) * sizeof(char));

	for (i = length - 1; i >= 0; i--)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}

	str[length] = '\0';

	return (str);
}