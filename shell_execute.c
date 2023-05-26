#include "shell.h"
int shell_cd(char **args);
int shell_exit(char **args);
int shell_ctrld(char **args);

char *builtin_str[] = {"cd", "exit", "^D"};

int (*builtin_func[]) (char **) = {&shell_cd, &shell_exit, &shell_ctrld};

/**
 * builtins_num - size
 * Return: size
 */

int builtins_num(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}


/**
 * shell_cd - builtin to change dirs
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: 1 on success
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * shell_exit - builtin to exit the shell
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int shell_exit(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * shell_ctrld - builtin to handle "^D" call
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int shell_ctrld(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 *_fork_exec - foo that create a fork.
 *@arg: Command and values path.
 *@av: Has the name of our program.
 *@env: Environment
 *@line: Command line for the user.
 *@np: ID of proces.
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork_exec(char **arg, char **av, char **env, char *line, int np, int c)
{

	pid_t child;
	int status, i = 0;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (i = 0; i < builtins_num(); i++)
	{
		if (_strcmp(arg[0], builtin_str[i]) == 0)
			return (builtin_func[i](arg));
	}
	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(line);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
