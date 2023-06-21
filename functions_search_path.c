#include "main.h"

char *get_correct_path(char **path_tokens, char *command);

/**
 * search_path - Search for the full path of a command
 * @command: The command to search for
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *search_path(char *command)
{
	char *path = NULL, **path_tokens = NULL, *correct_path = NULL;
	size_t command_len = _strlen(command);

	if (command[0] == '.' || command[0] == '/')
	{
		correct_path = malloc(command_len + 1);
		if (!correct_path)
		{
			return (NULL);
		}
		null_fill(correct_path, command_len + 1);
		correct_path = _strncpy(correct_path, command, command_len);
		correct_path[command_len] = '\0';
		if (access(correct_path, F_OK | X_OK) == 0)
		{
			return (correct_path);
		}
		_free(&correct_path);
		return (NULL);
	}

	path = get_path();
	path += 5;

	path_tokens = split(path, ":");
	if (!path_tokens)
	{
		return (NULL);
	}

	correct_path = get_correct_path(path_tokens, command);
	if (!correct_path)
	{
		_free_arr(&path_tokens);
		return (NULL);
	}

	_free_arr(&path_tokens);

	return (correct_path);
}


/**
 * get_correct_path - Search for the full path of a command
 * @path_tokens: path_tokens
 * @command: The command to search for
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *get_correct_path(char **path_tokens, char *command)
{
	size_t i = 0;
	size_t command_len = _strlen(command), path_len = 0, total_len = 0;
	char *correct_path = NULL;

	while (path_tokens[i])
	{
		path_len = _strlen(path_tokens[i]);
		total_len = path_len + command_len + 2;
		correct_path = malloc(total_len);
		if (!correct_path)
		{
			return (NULL);
		}
		null_fill(correct_path, total_len);
		correct_path = _strncpy(correct_path, path_tokens[i], path_len);
		correct_path = _strncat(correct_path, "/", 1);
		correct_path = _strncat(correct_path, command, command_len);
		if (access(correct_path, F_OK | X_OK) == 0)
		{
			return (correct_path);
		}
		_free(&correct_path);
		i++;
	}
	return (NULL);
}
