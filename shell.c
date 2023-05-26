#include "main.h"
/**
 * shell - Run the shell
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, -1 on failure
 */
ssize_t shell(char **argv)
{
	if (isatty(STDIN_FILENO))
	{
		return (shell_interactive(argv));
	}
	else
	{
		return (shell_noninteractive(argv));
	}
}
