#include "main.h"
/**
 * get_path - Retrieve the value of the PATH environment variable
 *
 * Return: A pointer to the value of the PATH variable,
 * or NULL if not found.
 */
char *get_path(void)
{
	int i = 0;
	char **envp = environ;

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
