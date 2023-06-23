#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int _strlen(char *str);
ssize_t _getline(char **lineptr, size_t *n, int fd);

int main(void)
{
	size_t n = 0;
	ssize_t readed;
	char *buff, *start = "$ ";

	/*
	printf("test");
	fflush(stdout);
	*/
	write(STDOUT_FILENO, start, _strlen(start));
	readed = _getline(&buff, &n, STDIN_FILENO);

	while (readed != -1)
	{
		write(STDOUT_FILENO, buff, _strlen(buff));
		write(STDOUT_FILENO, start, _strlen(start));
		readed = _getline(&buff, &n, STDIN_FILENO);
	}

	free(buff);
	return (-1);
}

/******************************************************************************/

ssize_t _getline(char **lineptr, size_t *bufsize, int fd)
{
	ssize_t total_readed = 0;
	size_t position = 0, new_size, i;
	char c, *new_buffer;

	if (!lineptr || !bufsize)
	{
		return (-1);
	}

	if (*lineptr == NULL || *bufsize == 0)
	{
		*bufsize = 128;
		*lineptr = malloc(*bufsize + 1);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	while (read(fd, &c, sizeof(c)) > 0)
	{
		total_readed++;
		(*lineptr)[position++] = c;

		if (c == '\n')
		{
			break;
		}

		if (position == *bufsize - 1)
		{
			new_size = *bufsize * 2;
			new_buffer = malloc(new_size + 1);
			if (new_buffer == NULL)
			{
				return (-1);
			}
			for (i = 0; i < position; i++)
			{
				new_buffer[i] = (*lineptr)[i];
			}
			free(*lineptr);
			*lineptr = new_buffer;
			*bufsize = new_size;
		}
		(*lineptr)[position] = '\0';
	}

	if (position == 0 && total_readed == 0)
	{
		return -1;
	}

	return (total_readed);
}
/******************************************************************************/
int _strlen(char *str)
{
	int len = 0;
	while (*(str++))
	{
		len++;
	}
	return (len);
}
