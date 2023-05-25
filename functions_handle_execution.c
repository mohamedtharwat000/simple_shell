#include "main.h"

void puts_onerror(char *shell_name, char *err_num);

/**
 * handle_execution - Execute a command
 * @readed: The input string read
 * @argv: The command-line arguments
 * @counter: Pointer to a counter for executed commands
 *
 * Return: 0 on success, -1 on failure.
 */
ssize_t handle_execution(char **readed, char **argv, size_t *counter)
{
	ssize_t builtin_num = -1, status = -1;
	char *command_path = NULL, **readed_argv = NULL, *counter_str = NULL;
	char *command = NULL;

	(*counter)++;

	readed_argv = split(*readed, " ");
	if (readed_argv == NULL)
	{
		return (status);
	}

	command = readed_argv[0];
	builtin_num = is_builtin(command);

	if (builtin_num != -1)
	{
		free(*readed);
		*readed = NULL;
		free_strarr(readed_argv);
		status = builtin_handler(builtin_num);
		return (status);
	}

	command_path = search_path(readed_argv[0]);
	if (command_path != NULL)
	{
		status = execute_fork(command_path, readed_argv);
		if (_strncmp(command_path, command, _strlen(command_path)) == 0)
		{
			free_strarr(readed_argv);
		}
		else
		{
			free(command_path);
			command_path = NULL;
			free_strarr(readed_argv);
		}
	}
	else
	{
		counter_str = numtostr(*counter);
		puts_onerror(argv[0], counter_str);
		free(counter_str);
		free_strarr(readed_argv);
	}

	return (status);
}


/**
 * puts_onerror - puts error
 * @shell_name: shell_name
 * @counter_str: counter_str
 * Return: void
 */
void puts_onerror(char *shell_name, char *counter_str)
{
	_puts(shell_name, STDOUT_FILENO);
	_puts(": ", STDOUT_FILENO);
	_puts(counter_str, STDOUT_FILENO);
	_puts(": ", STDOUT_FILENO);
}
