#include "header_main.h"


/**
 * handle_ctrlD - exits program if Ctrl-D was pressed
 * @index: characters read via get_line
 * @command: user's typed in command
 * @env: environmental variable linked list
 */
void handle_ctrlD(int index, char *command, env_list *env)
{
	if (index == 0)
	{
		free(command);
		free_linked_list(env);
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(0);
	}
}
