#include "main.h"
/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * @envp: Array of environment variable strings
 *
 * Return: Exit status of the program
 *
 */
int main(int argc, char **argv, char **envp)
{
	int status = 0;

	(void)argc;

	status = shell(argv, envp);

	return (status);
}
