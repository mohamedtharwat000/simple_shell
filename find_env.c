#include "header_main.h"

/**
 * find_env - find given environmental variable
 * @env: linked list
 * @str:  name
 * Return: index of node in linked list
 */
int find_env(env_list *env, char *str)
{
	int j = 0, index = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0')
		{
			break;
		}
		env = env->next;
		index++;
	}
	if (env == NULL)
	{
		return (-1);
	}
	return (index);
}
