#include "headers_shell.h"

/**
 * shell_exit - exit the shell.
 * @cmd: arg 1;
 * @global: arg 2.
 */
void shell_exit(char **cmd, global_t *global)
{
	int n;

	if (!cmd[1])
	{
		n = global->exit_code;
		free_all(global);
		exit(n);
	}
	else
	{
		if (!is_num(cmd[1]) || _atoi(cmd[1]) < 0)
		{
			_puts(global->name, 2, 0);
			_puts(": ", 2, 0);
			putnbr_fd(global->n, 2);
			_puts(": exit: Illegal number: ", 2, 0);
			_puts(cmd[1], 2, 1);
			global->exit_code = 2;
		}
		else
		{
			n = _atoi(cmd[1]);
			free_all(global);
			exit((unsigned char)n);
		}
	}
}
