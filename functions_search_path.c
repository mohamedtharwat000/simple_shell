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

	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, F_OK | X_OK) == 0)
		{
			return (command);
		}
		return (NULL);
	}

	path = get_path(environ);

	path_tokens = split_path(path);

	if (!path_tokens)
	{
		return (NULL);
	}

	correct_path = get_correct_path(path_tokens, command);

	free_strarr(path_tokens);

	return (correct_path);
}


/**
 * get_correct_path - Search for the full path of a command
 * @path_tokens: Array of path tokens
 * @command: The command to search for
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *get_correct_path(char **path_tokens, char *command)
{
	size_t i = 0, j = 0;
	size_t command_len = _strlen(command), path_len = 0, total_len = 0;
	char *correct_path = NULL;

	while (path_tokens[i])
	{
		path_len = _strlen(path_tokens[i]);
		total_len = path_len + command_len + 2;
		correct_path = malloc(total_len);
		if (!correct_path)
		{
			free_strarr(path_tokens);
			return (NULL);
		}
		for (j = 0; j < total_len; j++)
		{
			correct_path[j] = '\0';
		}
		_strncpy(correct_path, path_tokens[i], path_len);
		_strcat(correct_path, "/");
		_strcat(correct_path, command);
		if (access(correct_path, F_OK | X_OK) == 0)
		{
			return correct_path;
		}
		free(correct_path);
		correct_path = NULL;
		i++;
	}

	return NULL;
}
