#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t _getc(char *c, size_t fd)
{
	return (read(fd, c, sizeof(*c)));
}

int main(void)
{
	char c;
  ssize_t n = _getc(&c, 0);
	(void)n;
	printf("%c\n", c);
	return (0);
}