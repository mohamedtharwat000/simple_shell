#include "main.h"
/**
 * non_interactive_shell - Run a simple non-interactive shell.
 * @filename: Name of the file containing commands.
 * @argv: Array of strings representing command-line arguments.
 * @envp: Array of strings representing the environment variables.
 *
 * Return: -1 on failure.
 */
ssize_t non_interactive_shell(char *filename, char **argv, char **envp)
{
	char *buff_line = NULL, **buff_argv = NULL;
	size_t buff_size = 0, counter = 1;
	ssize_t read_length = 0, executed = 0;
	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
	{
		perror("");
		return (-1);
	}

	while ((read_length = getline(&buff_line, &buff_size, fp)) != -1)
	{
		buff_argv = split(buff_line, " ");
		if (buff_argv == NULL)
		{
			perror("");
			fclose(fp);
			return (-1);
		}
		executed = exec_buff(buff_argv[0], buff_argv, &counter, argv, envp);
		if (executed == -1)
		{
			perror("");
			free_strarr(buff_argv);
			fclose(fp);
			return(-1);
		}
		free_strarr(buff_argv);
	}

	free(buff_line);
	fclose(fp);
	return (0);
}
