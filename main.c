#include "header_main.h"

/**
 * main - creates a simple shell
 * @ac: argument count
 * @av: argument vectors
 * @env: environmental variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	/* Prompt user */
	Shell_start(env);

	return (0);
}
