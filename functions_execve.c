#include "main.h"

char *ntos(size_t num) {
  char *str = malloc(sizeof(char) * 10);
  int i = 0;

  while (num > 0) {
    str[i++] = (num % 10) + '0';
    num /= 10;
  }

  str[i] = '\0';

  return str;
}

/**
 * exec_buff - Execute a command in the shell.
 * @buff: Command to be executed.
 * @argv: Array of strings representing command-line arguments.
 * @envp: Array of strings representing the environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int exec_buff(char *command, char **command_argv, size_t *counter, char **argv, char **envp)
{
	pid_t pid;
	int status;
	char *path_var = get_path(envp);
	char *path = search_path(command, path_var);

	if (path == NULL)
	{
		_puts(argv[0], STDOUT_FILENO);
		_puts(": ", STDOUT_FILENO);
		_puts(ntos(*counter), STDOUT_FILENO);
		perror("");
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
		if (execve(path, command_argv, envp) == -1)
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
