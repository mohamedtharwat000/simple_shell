#include "header_main.h"


/**
 * handle_unsetenv - handle unset variable
 * @env: linked list
 * @str: user's typed in command
 * Return: 0 on success
 */
int handle_unsetenv(env_list **env, char **str)
{
	int index = 0, j = 0;

	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_string_2d(str);
		return (-1);
	}
	index = find_env(*env, str[1]);
	free_string_2d(str);
	if (index == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	j = delete_nodeint_at_index(env, index);
	if (j == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}


	return (0);
}
