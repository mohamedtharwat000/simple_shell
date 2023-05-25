#include "header_main.h"

/**
 * ignore_spaces - custom ignores spaces and newlines
 * @str: envrionmental variables
 * Return: new string
 */
char *ignore_spaces(char *str)
{
	while (*str == ' ' || *str == '\n')
	{
		str++;
	}
	return (str);
}
