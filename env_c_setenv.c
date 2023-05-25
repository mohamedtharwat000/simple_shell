#include "header_main.h"



/**
 * handle_c_setenv -  handle_setenv
 * @env: environmental variable linked list
 * @name: environmental variable name
 * @dir: directory path
 * Return: 0 on success
 */
int handle_c_setenv(env_list **env, char *name, char *dir)
{
	int index = 0, j = 0;
	char *cat;
	env_list *holder;

	cat = _strdup(name);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, dir);
	index = find_env(*env, name);

	holder = *env;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->var);
	holder->var = _strdup(cat);
	free(cat);
	return (0);
}
