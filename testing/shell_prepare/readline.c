#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	size_t n;
	ssize_t readed;
	char *buff;

	printf("$ ");
	readed = getline(&buff, &n, stdin);
	while (readed != -1)
	{
		printf("%s", buff);
		printf("$ ");
		readed = getline(&buff, &n, stdin);
	}

	free(buff);
	return (-1);
}
