#include "header_main.h"

/**
 * ignore_delm - returns a version of string without preceeding delims
 * @str: string
 * @delm: delimiter
 * Return: new string
 */
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
	{
		str++;
	}
	return (str);
}
