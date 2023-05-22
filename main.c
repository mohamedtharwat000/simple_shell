#include "main.h"

/**
 * main - Simple shell implementation.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of strings representing arguments passed to the program.
 * @envp: Array of strings representing the environment variables.
 *
 * Return: 0 on success or -1 on failure.
 */
int main(int argc, char **argv, char **envp)
{
	int status = 0;

	if (argc < 2)
	{
		status = interactive_shell(argv, envp);
	}
	else
	{
		status = non_interactive_shell(argv, envp);
	}

	return (status);
}
