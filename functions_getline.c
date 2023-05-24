#include "main.h"

ssize_t _getline_read(char *line, size_t size, size_t fd);

/**
 * _getline - Reads a line of input from a file stream
 * @buff_line: buffer that will store the read line
 * @buff_size: size of the buffer
 * @fd: file discriptor to read from
 *
 * Return: On success, the function returns the number of characters read,
 * including the newline character, but excluding the null terminator.
 * On failure, it returns -1.
 *
 * The caller is responsible for freeing the memory allocated for *lineptr
 * when it is no longer needed.
 */
ssize_t _getline(char **buff_line, size_t *buff_size, FILE *fd)
{
	size_t size = *buff_size;

	if (buff_line == NULL || buff_size == NULL || fd == NULL)
	{
		return (-1);
	}

	if (size == 0)
	{
		size = 1024;
		*buff_line = malloc(size);
		if (buff_line == NULL)
		{
			return (-1);
		}
	}

	return (_getline_read(*buff_line, size, fd->_fileno));
}



/**
 * _getline_read - Reads a line of input from a file descriptor
 * @line: Pointer to a buffer that will store the read line
 * @size: Pointer to the size of the buffer
 * @fd: File descriptor to read from
 *
 * Return: On success, the function returns the number of characters read,
 * including the newline character, but excluding the null terminator. On
 * failure, it returns -1.
 *
 */
ssize_t _getline_read(char *line, size_t size, size_t fd)
{
	ssize_t readed = 0;
	size_t i = 0;
	char c = '\0', *new_buffer = NULL;

	while (_getc(&c, fd) > 0)
	{
		readed++;
		line[i++] = c;
		if (c == '\n')
		{
			break;
		}

		if (i == size - 1)
		{
			size *= 2;
			new_buffer = malloc(size);
			if (new_buffer == NULL)
			{
				free(line);
				return (-1);
			}
			free(line);
			line = new_buffer;
		}
	}

	if (readed <= 0)
	{
		free(line);
		return (-1);
	}

	line[i] = '\0';
	line[i - 1] = '\0';
	return (readed);
}


