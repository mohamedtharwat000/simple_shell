#include "main.h"
/**
 * shell_noninteractive - Run the shell in non-interactive mode
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, -1 on failure
 */
ssize_t shell_noninteractive(char **argv)
{
	char *buff_line = NULL;
	ssize_t readed = 0, executed = 0;
	size_t run_counter = 0;
	static size_t buff_size;

	readed = _getline(&buff_line, &buff_size, stdin);
	if (readed <= 0)
	{
		perror("");
		free(buff_line);
		return (-1);
	}
	executed = handle_execution(&buff_line, argv, &run_counter);
	if (executed < 0)
	{
		perror("");
		free(buff_line);
		return (-1);
	}

	return (0);
}
