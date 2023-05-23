#include "main.h"

/**
 * interactive_shell - Run a simple interactive shell.
 * @argv: Array of strings representing command-line arguments.
 * @envp: Array of strings representing the environment variables.
 *
 * Return: -1 on failure.
 */
ssize_t interactive_shell(char **argv, char **envp)
{
	char *buff_line = NULL, **buff_argv = NULL, *shell_start = "$ ";
	size_t buff_size = 0, counter = 1;
	ssize_t read_length = 0, write_length = 0, executed = 0;

	while (1)
	{
		write_length = _puts(shell_start, STDOUT_FILENO);
		if (write_length < 0)
		{
			perror("");
			return (-1);
		}
		read_length = _getline(&buff_line, &buff_size, stdin);
		if (read_length < 1)
		{
			perror("");
			return (-1);
		}
		buff_argv = split(buff_line, " ");
		if (buff_argv == NULL)
		{
			perror("");
			return (-1);
		}
		executed = exec_buff(buff_argv[0], buff_argv, &counter, argv, envp);
		if (executed == -1)
		{
			perror("");
			free_strarr(buff_argv);
			return (-1);
		}
	}

	free(buff_line);
	free_strarr(buff_argv);
	return (0);
}
