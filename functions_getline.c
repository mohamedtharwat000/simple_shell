#include "main.h"

ssize_t _getline_read(char *line, size_t size, size_t fd);


/**
 * _getline - Reads a line of input from a file stream
 * @buff_line: buffer that will store the read line
 * @bufsize: size of the buffer
 * @fd: file discriptor to read from
 *
 * Return: On success, the function returns the number of characters read,
 * including the newline character, but excluding the null terminator.
 * On failure, it returns -1.
 *
 * The caller is responsible for freeing the memory allocated for *lineptr
 * when it is no longer needed.
 */
ssize_t _getline(char *buff_line, size_t buff_size, size_t fd)
{

	if (buff_size == 0)
	{
		buff_size = BUFFSIZE;
		buff_line = malloc(buff_size);
		if (buff_line == NULL)
		{
			return (-1);
		}
	}

	return (_getline_read(buff_line, buff_size, fd));
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
 * The caller is responsible for freeing the memory allocated for *lineptr
 * when it is no longer needed.
 */
ssize_t _getline_read(char *line, size_t size, size_t fd)
{
	ssize_t total_readed = 0;
	size_t index = 0;
	char c, *new_buffer;

	while (_getc(&c, fd) > 0)
	{
		total_readed++;
		line[index++] = c;
		if (c == '\n')
		{
			break;
		}

		if (index == size - 1)
		{
			size= size * 2;
			new_buffer = malloc(size);
			if (new_buffer == NULL)
			{
				return (-1);
			}
			_strncpy(new_buffer, line, index);
			free(line);
			line = new_buffer;
			free(new_buffer);
		}
	}

	if (total_readed <= 0)
	{
		free(line);
		return (-1);
	}

	line[index] = '\0';

	return (total_readed);
}


