#include "main.h"
/**
 * search_path - Search for the full path of a command
 * @command: The command to search for
 * @path: The PATH environment variable string
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *search_path(char *command, char *path)
{
	size_t i = 0, j = 0, k = 0;
	size_t len_command = _strlen(command), path_len = 0, len = 0;
	char **path_tokens, *correct_path;

	path_tokens = split_path(path);

	for (i = 0; path_tokens[i]; i++)
	{
		path_len = _strlen(path_tokens[i]);
		len = path_len + len_command + 2;
		correct_path = malloc(sizeof(char) * len);
		if (!correct_path)
		{
			return (NULL);
		}
		for (j = 0; j < path_len; j++)
		{
			correct_path[j] = path_tokens[i][j];
		}
		correct_path[j++] = '/';
		for (; j < len; j++)
		{
			correct_path[j] = command[k++];
		}
		correct_path[len - 1] = '\0';
		if (access(correct_path, F_OK | X_OK) == 0)
		{
			free_strarr(path_tokens);
			return (correct_path);
		}
		free(correct_path);
		k = 0;
	}

	free_strarr(path_tokens);
	return (NULL);
}
