#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int ac, char **av, char **env)
{
	int i = 0;
	char *var = "SHELL";

	(void)ac;
	(void)av;

	while (env[i] != NULL)
	{
		if (strncmp(env[i], var, strlen(var)) == 0)
		{
			printf("%s\n", env[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

