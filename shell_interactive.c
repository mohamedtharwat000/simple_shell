#include "main.h"
/**
 * shell_interactive - Run the shell in interactive mode
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 *
 * Return: 0 on success, -1 on failure
 */
ssize_t shell_interactive(char **argv, char **envp)
{
	char *buff_line = NULL, *shell_start = "$ ";
	ssize_t readed = 0, writed = 0, executed = 0;
	static size_t buff_size;
	int run_counter = 0;

	while (1)
	{
		writed = _puts(shell_start, STDOUT_FILENO);
		if (writed < 0)
		{
			perror("");
			return (-1);
		}
		readed = _getline(&buff_line, &buff_size, stdin);
		if (readed < 0)
		{
			perror("");
			return (-1);
		}
		executed = handle_execution(buff_line, argv, envp, &run_counter);
		if (executed < 0)
		{
			perror("");
		}

	}

	free(buff_line);

	return (0);
}