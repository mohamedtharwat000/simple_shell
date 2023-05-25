#include "header_main.h"


/**
 * handle_cd - shell builtin cd
 * @str: command
 * @env: enviromental linked list
 * @num: nth user command
 * Return: 0 if good 2 if bad
 */
int handle_cd(char **str, env_list *env, int num)
{
	char *current = NULL, *dir = NULL;
	int exit_stat = 0;

	current = getcwd(current, 0);
	if (str[1] != NULL)
	{
		if (str[1][0] == '~')
		{
			dir = get_env("HOME", env);
			dir = handle_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-')
		{
			if (str[1][1] == '\0')
			{
				dir = get_env("OLDPWD", env);
			}
		}
		else
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, str[1]);
			}
			else
			{
				dir = _strdup(str[1]);
			}
		}
		exit_stat = handle_cd_execute(env, current, dir, str[1], num);
		free(dir);
	}
	else
	{
		handle_cd_only(env, current);
	}
	free_string_2d(str);
	return (exit_stat);
}
