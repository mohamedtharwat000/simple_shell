#include "headers_shell.h"
/**
 * env_print - prints the environment.
 * @cmd: arg 1.
 * @global: arg 2.
 */
void env_print(char **cmd, global_t *global)
{
	env_t *ptr = global->env;

	(void)cmd;
	while (ptr)
	{
		if (ptr->name)
		{
			_puts(ptr->name, 1, 0);
			_puts("=", 1, 0);
			_puts(ptr->value, 1, 1);
		}
		ptr = ptr->next;
	}
	global->exit_code = 0;
}
