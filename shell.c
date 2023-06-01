#include "main.h"
/**
 * shell - Run the shell
 *
 * Return: 0 on success, -1 on failure
 */
ssize_t shell(void)
{
	if (isatty(STDIN_FILENO))
	{
		return (shell_interactive());
	}
	else
	{
		return (shell_noninteractive());
	}
}
