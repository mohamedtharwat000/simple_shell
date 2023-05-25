#include "header_main.h"

/**
 * handle_cd_execute - executes the cd
 * @env: environmental linked list
 * @current: cwd
 * @dir: directory
 * @str: string
 * @num: number
 * Return: 0 if good 2 if bad
 */
int handle_cd_execute(env_list *env, char *current,
											 char *dir, char *str, int num)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		handle_c_setenv(&env, "OLDPWD", current);
		free(current);
		chdir(dir);
		current = NULL;
		current = getcwd(current, 0);
		handle_c_setenv(&env, "PWD", current);
		free(current);
	}
	else
	{
		cant_cd_to(str, num, env);
		free(current);
		i = 2;
	}
	return (i);
}
