#include "main.h"

/**
 * exec_buff - Execute a command in the shell.
 * @buff: Command to be executed.
 * @argv: Array of strings representing command-line arguments.
 * @envp: Array of strings representing the environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int exec_buff(char *command, char **buff_argv, char **argv, char **envp)
{
	pid_t pid;
	int status;
	char *path = get_path(envp);
	char *correct_path = search_path(command, path);

	if (correct_path == NULL)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror(argv[0]);
			return (-1);
		}
	}

	if (pid == 0)
	{
		if (execve(correct_path, buff_argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
