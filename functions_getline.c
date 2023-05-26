#include "main.h"

/**
 * _getline - Reads a line of input from a file stream
 * @buff_line: buffer that will store the read line
 * @buff_size: size of the buffer
 * @fd: file descriptor to read from
 *
 * Return: On success, the function returns the number of characters read,
 * including the newline character, but excluding the null terminator.
 * On failure, it returns -1.
 *
 * The caller is responsible for freeing the memory allocated buff_line
 * when it is no longer needed.
 */
ssize_t _getline(char **buff_line, size_t *buff_size, FILE *fd)
{
	ssize_t readed = 0;
	size_t i = 0;
	char c = '\0', *new_buffer = NULL;

	if (buff_line == NULL || buff_size == NULL || fd == NULL)
	{
		return (-1);
	}
	if (*buff_size == 0 || *buff_line == NULL)
	{
		*buff_size = 1024;
		*buff_line = malloc(*buff_size);
		if (*buff_line == NULL)
			return (-1);
	}
	while (_getc(&c, fd->_fileno) > 0)
	{
		readed++;
		if (c == '\n')
		{
			break;
		}
		if (i == *buff_size - 1)
		{
			*buff_size *= 2;
			new_buffer = malloc(*buff_size);
			if (new_buffer == NULL)
			{
				free(*buff_line);
				return (-1);
			}
			_strncpy(new_buffer, *buff_line, i);
			free(*buff_line);
			*buff_line = new_buffer;
		}
		(*buff_line)[i++] = c;
		(*buff_line)[i] = '\0';
	}
	return (readed);
}
