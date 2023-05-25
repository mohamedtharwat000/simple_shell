#include "header_main.h"

/**
 * _execve - execute command user typed into shell
 * @s: command user typed
 * @env: environmental variable
 * @num: nth user command; to be used in error message
 * Return: 0 on success
 */
int _execve(char **s, env_list *env, int num)
{
	char *holder;
	int status = 0, t = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		holder = s[0];
		t = 1;
	}
	else
		holder = handle_which(s[0], env);
	if (access(holder, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_string_2d(s);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(holder, s, NULL) == -1)
			{
				not_found(s[0], num, env);
				free_on_exit(s, env);
			}
		}
		else
		{
			wait(&status);
			free_string_2d(s);
			if (t == 0)
				free(holder);
		}
	}
	return (0);
}
