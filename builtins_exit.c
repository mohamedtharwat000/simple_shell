#include "header_main.h"



/**
 * handle_exit - handle exit
 * @str: command
 * @env: environmental variable
 * @num: number
 * @command: command
 * Return: 0 if good 2 if bad
 */
int handle_exit(char **str, env_list *env, int num, char **command)
{
	int e_value = 0;

	if (str[1] != NULL)
	{
		e_value = _atoi(str[1]);
	}

	if (e_value == -1)
	{
		illegal_number(str[1], num, env);
		free_string_2d(str);
		return (2);
	}
	free_string_2d(str);
	free_linked_list(env);
	if (command != NULL)
	{
		free_string_2d(command);
	}
	exit(e_value);
}
