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
	else if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		return (EXIT_FAILURE);
	}
	char *filename = argv[1];
	ssize_t ret = non_interactive_shell(filename, argv, envp);
	if (ret == -1)
	{
		fprintf(stderr, "Error: Failed to run non-interactive shell.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
