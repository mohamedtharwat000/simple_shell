#include "main.h"
/**
 * shell - Run the shell
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 *
 * Return: 0 on success, -1 on failure
 */
ssize_t shell(char **argv, char **envp)
{
	if (!isatty(STDIN_FILENO))
	{
		return (shell_noninteractive(argv, envp));
	}
	else
	{
		return (shell_interactive(argv, envp));
	}
}
