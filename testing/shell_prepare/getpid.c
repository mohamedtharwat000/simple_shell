#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t process_id = getpid();
	printf("%d\n", process_id);
	return 0;
}
