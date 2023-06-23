#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t ppid = getppid();
	printf("%d\n", ppid);
	return (0);
}
