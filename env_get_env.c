#include "header_main.h"



/**
 * get_env - finds and returns a copy of the requested environmental variable
 * @str: string to store it in
 * @env: entire set of environmental variables
 * Return: copy of requested environmental variable
 */
char *get_env(char *str, env_list *env)
{
	int j = 0, cs = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0' && (env->var)[j] == '=')
			break;
		env = env->next;
	}

	while (str[cs] != '\0')
		cs++;
	cs++;
	return (handle_str_duplicate(env->var, cs));
}
