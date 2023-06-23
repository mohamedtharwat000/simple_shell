#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	printf("%p\n", (void*)&env);
	printf("%p\n", (void*)&environ);
	return (0);
}
