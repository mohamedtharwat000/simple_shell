#include "main.h"
/**
 * shell_noninteractive - Run the shell in non-interactive mode
 *
 * Return: 0 on success, -1 on failure
 */
ssize_t shell_noninteractive(void)
{
	char *buff_line = NULL;
	static size_t buff_size, run_counter;
	ssize_t readed = 0, executed = 0, status = 0;
	size_t total_readed = 0;

	while (readed >= 0)
	{
		readed = _getline(&buff_line, &buff_size, stdin);

		if (readed < 0)
		{
			status = -1;
			return (status);
		}

		if (readed > 0)
		{
			total_readed += readed;
			buff_line += readed;
		}

		if (readed == 0)
		{
			break;
		}
	}

	buff_line -= total_readed;

	executed = handle_execution(&buff_line, &run_counter);

	return (executed);
}
