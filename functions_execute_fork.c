#include "main.h"
/**
 * execute_fork - Execute a command using fork and execve
 * @command_path: The path of the command to execute
 * @readed_argv: The arguments for the command
 * @envp: The environment variables
 *
 * Return: 0 on success, -1 on failure.
 */
ssize_t execute_fork(char *command_path, char **readed_argv, char **envp)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(command_path, readed_argv, envp) == -1)
		{
			perror("");
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
