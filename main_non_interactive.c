#include "header_main.h"
/**
 * handle_non_interactive - handles non interactive
 * @env: envrionmental variables
 */
void handle_non_interactive(env_list *env)
{
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command = NULL, *n_command = NULL, **n_line, **token;

	i = get_line(&command);
	if (i == 0)
	{
		free(command);
		exit(0);
	}
	n_command = command;
	command = ignore_spaces(command);
	n_line = _string_tokens(command, "\n");
	if (n_command != NULL)
		free(n_command);
	n = 0;
	while (n_line[n] != NULL)
	{
		command_line_no++;
		token = NULL;
		token = _string_tokens(n_line[n], " ");
		exit_stat = handle_built_in(token, env, command_line_no, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _execve(token, env, command_line_no);
		n++;
	}
	free_string_2d(n_line);
	free_linked_list(env);
	exit(exit_stat);
}
