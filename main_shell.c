#include "header_main.h"


/**
 * Shell_start - repeatedly prompts user and executes user's cmds if applicable
 * @en: envrionmental variables
 * Return: 0 on success
 */
int Shell_start(char **en)
{
	env_list *env;
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		command_line_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			handle_non_interactive(env);
		signal(SIGINT, handle_ctrlC);
		command = NULL;
		i = 0;
		i = get_line(&command);
		handle_ctrlD(i, command, env);
		n_command = command;
		command = ignore_space(command);
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = _string_tokens(command, " ");
		if (n_command != NULL)
			free(n_command);
		exit_stat = handle_built_in(token, env, command_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(token, env, command_line_no);
	} while (1);
	return (exit_stat);
}
