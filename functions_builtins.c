#include "main.h"

ssize_t handle_exit(void);
ssize_t handle_env(void);

/**
 * builtin_handler - Handle built-in commands
 * @builtin: number -> builtin command
 *
 * Return: 0 if a match is found and handled, -1 otherwise.
 */
ssize_t builtin_handler(ssize_t builtin)
{
	ssize_t i = 0;
	builtin_t builtins[] = {
		{"exit", handle_exit},
		{"env", handle_env},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].command; i++)
	{
		if (i == builtin)
		{
			builtins[i].handle_command();
			return (0);
		}
	}

	return (-1);
}


/**
 * handle_exit - Handle the "exit" command
 *
 * If the command argument is provided,
 * it converts it to an integer and exits the program with that value.
 * If no argument is provided, the program exits with a value of 0.
 *
 * Return: always 0.
 */
ssize_t handle_exit(void)
{
	exit(1);
	return (0);
}

/**
 * handle_env - Handle the "env" command
 *
 * Prints the environment variables.
 * Return: always 0.
 */
ssize_t handle_env(void)
{
	char **envp = environ;

	while (*envp != NULL)
	{
		puts(*envp);
		envp++;
	}

	return (0);
}
