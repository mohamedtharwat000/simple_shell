#include <stdio.h>

extern char **environ;

int main(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
