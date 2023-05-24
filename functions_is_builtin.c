#include "main.h"
/**
 * is_builtin - Check if a command is a built-in command
 * @user_input: The user input command to check
 *
 * Return: 0 if the command is a built-in command, -1 otherwise
 */
ssize_t is_builtin(char *user_input)
{
	size_t i = 0;
	char *builtins[] = {
		"exit",
		"env",
		NULL
	};

	for (i = 0; builtins[i]; i++)
	{
		if (_strncmp(user_input, builtins[i],
								 _strlen(user_input)) == 0)
		{
			return (0);
		}
	}

	return (-1);
}
