#include "header_main.h"

/**
 * handle_built_in - handles builtins
 * @token: command
 * @env: env list
 * @num: int
 * @command: command
 * Return: 1 if good, 0 if bad
 */
int handle_built_in(char **token, env_list *env, int num, char **command)
{
	int i = 0;


	if (_strcmp(token[0], "exit") == 0)
	{
		i = handle_exit(token, env, num, command);
	}
	else if (_strcmp(token[0], "env") == 0)
	{
		print_env(token, env);
		i = 1;
	}
	else if (_strcmp(token[0], "cd") == 0)
	{
		i = handle_cd(token, env, num);
	}
	else if (_strcmp(token[0], "setenv") == 0)
	{
		handle_setenv(&env, token);
		i = 1;
	}
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		handle_unsetenv(&env, token);
		i = 1;
	}


	return (i);
}
