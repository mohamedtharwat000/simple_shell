#include "header_main.h"

/**
 * handle_setenv - set env
 * @env: linked list
 * @str: user's typed in command
 * Return: 0 on success, 1 on fail
 */
int handle_setenv(env_list **env, char **str)
{
	int index = 0, j = 0;
	char *cat;
	env_list *holder;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_string_2d(str);
		return (-1);
	}
	cat = _strdup(str[1]);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, str[2]);
	index = find_env(*env, str[1]);
	if (index == -1)
	{
		handle_add_end_node(env, cat);
	}
	else
	{
		holder = *env;
		while (j < index)
		{
			holder = holder->next;
			j++;
		}
		free(holder->var);
		holder->var = _strdup(cat);
	}
	free(cat);
	free_string_2d(str);
	return (0);
}
