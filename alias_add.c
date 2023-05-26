#include "headers_shell.h"

/**
 * _alias - add or print alias.
 * @cmd: arg 1.
 * @global: arg 2.
 */
void _alias(char **cmd, global_t *global)
{
	alias_t *ptr = global->alias;
	int		i = 1;

	global->exit_code = 0;
	if (!cmd[1])
	{
		while (ptr)
		{
			_puts(ptr->name, 1, 0);
			_puts("='", 1, 0);
			_puts(ptr->value, 1, 0);
			_puts("'", 1, 1);
			ptr = ptr->next;
		}
	}
	else
	{
		help__alias(cmd, global);
		while (cmd[i])
		{
			if (!alias_search(cmd[i], global) && !is_new(cmd[i]))
			{
				_puts("alias: ", 2, 0);
				_puts(cmd[i], 2, 0);
				_puts(" not found", 2, 1);
				global->exit_code = 1;
			}
			i++;
		}
	}
}
