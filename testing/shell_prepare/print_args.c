#include <stdlib.h>
#include <stdio.h>

int main(int __attribute__((unused)) ac, char **av)
{
	int i;
	char *tmp[] = {"hello", "world", NULL};
	av = tmp;

	for (i = 0; av[i]; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
	}
