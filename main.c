#include "main.h"

/**
 * main - simple shell implementation.
 * @argc: number of argument passed to the program.
 * @argv: array of strings represent the argument passed to the program.
 * @env: enviroment variable passed to the program.
 */

int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv, char __attribute__((unused)) **env)
{
	int status;

	if (argc == 1)
	{
		status = interactive_shell();
	}
	else
	{
		/* status = non_interactive_shell(); */
	}

	if (status == -1)
	{
		return (1);
	}
	return 0;
}
