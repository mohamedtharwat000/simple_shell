#include "main.h"

/**
 * get_path - Retrieve the value of the PATH environment variable
 * @envp: Pointer to the array of environment variables
 *
 * This function searches for the PATH environment variable within the provided
 * environment variable array and returns its corresponding value.
 *
 * @envp should be a pointer to a NULL-terminated array of strings representing
 * the environment variables. Each element in the array has the format
 * "NAME=VALUE".
 *
 * Return: On success, the function returns a pointer to the value of the PATH
 * environment variable. If the PATH variable is not found, it returns NULL.
 *
 * Note: The returned pointer points to the actual value within the @envp array,
 * so it should not be modified or freed by the caller.
 */
char *get_path(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		if (_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i]);
		}
		i++;
	}

	return (NULL);
}

/**
 * split_path - Split the PATH variable into individual directory tokens
 * @path: The value of the PATH environment variable
 *
 * This function takes the value of the PATH environment variable and splits it
 * into individual directory tokens. Each token represents a directory in the
 * search path.
 *
 * @path should be a pointer to a string representing the value of the PATH
 * environment variable. It should be in the format "PATH=dir1:dir2:dir3:...".
 *
 * Return: On success, the function returns a pointer to an array of strings,
 * where each element represents a directory token. The array is terminated with
 * a NULL pointer. If @path is NULL or the splitting operation fails,
 * NULL is returned.
 *
 * Note: The caller is responsible for freeing the memory allocated for the
 * returned array and its elements.
 */
char **split_path(char *path)
{
	char **path_tokens;

	path += 5; /* Skip "PATH=" */
	path_tokens = split(path, ":");

	return (path_tokens);
}

/**
 * search_path - Search for a command in the directories specified by PATH
 * @command: The command to search for
 * @path: The value of the PATH environment variable
 *
 * This function searches for the given @command in the directories specified
 * by the @path variable. It constructs the full path for the command by
 * combining each directory token in @path with the @command.
 *
 * @command should be a pointer to a null-terminated string representing the
 * command to search for.
 *
 * @path should be a pointer to a string representing the value of the PATH
 * environment variable. It should be in the format "PATH=dir1:dir2:dir3:...".
 *
 * Return: On success, the function returns a pointer to a dynamically allocated
 * string representing the full path of the command. The returned string should
 * be freed by the caller. If the command is not found or an error occurs,
 * NULL is returned.
 *
 * Note: The caller is responsible for freeing the memory allocated for the
 * returned string.
 */
char *search_path(char *command, char *path)
{
	size_t i = 0, j = 0, k = 0;
	size_t len_command = _strlen(command), len_path_token = 0, len = 0;
	char **path_tokens, *correct_path;

	path_tokens = split_path(path);

	for (i = 0; path_tokens[i]; i++)
	{
		len_path_token = _strlen(path_tokens[i]);
		len = len_path_token + len_command + 2;
		correct_path = malloc(sizeof(char) * len);
		if (!correct_path)
		{
			return (NULL);
		}
		for (j = 0; j < len_path_token; j++)
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
			return (correct_path);
		}
		else
		{
			free(correct_path);
			break;
		}
	}
	return (NULL);
}
