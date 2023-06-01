#include "main.h"
/**
 * is_builtin - Check if a command is a built-in command
 * @command: The user input command to check
 *
 * Return: 0 if the command is a built-in command, -1 otherwise
 */
ssize_t is_builtin(char *command)
{
	ssize_t builtin = 0;
	char *builtins[] = {
		"exit",
		"env",
		NULL
	};

	for (builtin = 0; builtins[builtin]; builtin++)
	{
		if (_strncmp(command, builtins[builtin], _strlen(command)) == 0)
		{
			return (builtin);
		}
	}

	return (-1);
}
