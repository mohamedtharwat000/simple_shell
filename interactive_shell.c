#include "main.h"

/*
 * interactive_shell - function that runs a simple interactive shell.
 */


int interactive_shell(void)
{
	size_t n = 0;
	ssize_t gl;
	char *buff = NULL;

	printf("$ ");
	gl = getline(&buff, &n, stdin);
	while (gl != -1)
	{
		if (gl > 0)
		{
			printf("%s", buff);
		}
		printf("$ ");
		gl = getline(&buff, &n, stdin);
	}

	free(buff);
	return (0);
}
