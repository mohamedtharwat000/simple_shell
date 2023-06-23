#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int i;
	pid_t pid;

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
		}

		if (pid == 0)
		{
			execlp("ls", "ls", "-l", "/tmp", NULL);
		}
		else
		{
			wait(NULL);
		}

	}

	return 0;
}
