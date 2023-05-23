#include "main.h"


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