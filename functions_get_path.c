#include "main.h"
/**
 * get_path - Retrieve the value of the PATH environment variable
 * @envp: The array of environment variables
 *
 * Return: A pointer to the value of the PATH variable,
 * or NULL if not found.
 */
char *get_path(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		if (_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i]);
		}
		i++;
	}

	return (NULL);
}
