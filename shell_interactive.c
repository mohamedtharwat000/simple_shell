#include "main.h"
/**
 * shell_interactive - Run the shell in interactive mode
 *
 * Return: 0 on success, -1 on failure
 */
ssize_t shell_interactive(void)
{
	char *buff_line = NULL, *shell_start = "$ ";
	static size_t buff_size, run_counter;
	ssize_t readed = 0, writed = 0, executed = 0, status = 0;

	while (status == 0)
	{

		writed = _puts(shell_start, STDOUT_FILENO);
		if (writed < 0)
		{
			status = -1;
			return (status);
		}

		readed = _getline(&buff_line, &buff_size, stdin);
		if (readed <= 0)
		{
			status = -1;
			return (status);
		}

		executed = handle_execution(&buff_line, &run_counter);
		(void)executed;

	}
	return (status);
}
