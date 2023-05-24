#include "main.h"

ssize_t handle_exit(char *command);
ssize_t handle_env(char *command);

/**
 * builtin_handler - Handle built-in commands
 * @readed_argv: Array of command-line arguments
 *
 * Return: 0 if a match is found and handled, -1 otherwise.
 */
ssize_t builtin_handler(char **readed_argv)
{
	size_t i = 0;
	builtin builtins[] = {
		{"exit", handle_exit},
		{"env", handle_env},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].command; i++)
	{
		if (_strncmp(readed_argv[0], builtins[i].command,
								 _strlen(builtins[i].command)) == 0)
		{
			builtins[i].handle_command(readed_argv[1]);
			return (0);
		}
	}

	return (-1);
}


/**
 * handle_exit - Handle the "exit" command
 * @command: The command argument (optional)
 *
 * If the command argument is provided,
 * it converts it to an integer and exits the program with that value.
 * If no argument is provided, the program exits with a value of 0.
 *
 * Return: always 0.
 */
ssize_t handle_exit(char *command)
{
	if (command == NULL)
	{
		exit(0);
	}
	else
	{
		exit(string_to_number(command));
	}
	return (0);
}

/**
 * handle_env - Handle the "env" command
 * @command: The command argument (optional)
 *
 * Prints the environment variables.
 * Return: always 0.
 */
ssize_t handle_env(char *command)
{
	char **envp = environ;
	(void)command;

	while (*envp != NULL)
	{
		puts(*envp);
		envp++;
	}

	return (0);
}
