#include "header_main.h"

/**
 * handle_ctrlC - ignore Ctrl-C input and prints prompt again
 * @n: int
 */
void handle_ctrlC(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}
