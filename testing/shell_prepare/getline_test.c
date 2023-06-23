#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

ssize_t _getline_read(char *line, size_t size, size_t fd);

ssize_t _getc(char *c, size_t fd)
{
	return (read(fd, c, sizeof(*c)));
}

ssize_t _getline(char **buff_line, size_t *buff_size, FILE *fd)
{
  if (buff_line == NULL || buff_size == NULL || fd == NULL)
  {
    return (-1);
  }

	if (*buff_size == 0)
	{
		*buff_size = 1024;
		*buff_line = malloc(*buff_size);
		if (buff_line == NULL)
		{
			return (-1);
		}
	}

	return (_getline_read(*buff_line, *buff_size, fd->_fileno));
}


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

	return (readed);
}

int main(void)
{
  ssize_t readed = 0;
  size_t size = 0;
  char *line = NULL;
  readed = _getline(&line, &size, stdin);
  printf("%s%ld\n", line, readed);
  free(line);
  return (0);
}