#include "header_main.h"

/**
 * get_line - stores into malloced buffer the user's command into shell
 * @str: buffer
 * Return: number of characters read
 */
size_t get_line(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[BUFFSIZE];

	while (t2 == 0 && (i = read(STDIN_FILENO, buff, BUFFSIZE - 1)))
	{
		if (i == -1)
		{
			return (-1);
		}

		buff[i] = '\0';

		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
			{
				t2 = 1;
			}
			n++;
		}

		if (t == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buff);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			*str = _strcat(*str, buff);
		}
	}
	return (size);
}
