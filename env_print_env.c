#include "header_main.h"


/**
 * print_env - prints environmental variables
 * @str: user's command into shell
 * @env: environmental variables
 * Return: 0 on success
 */
int print_env(char **str, env_list *env)
{
	free_string_2d(str);
	print_list(env);
	return (0);
}
