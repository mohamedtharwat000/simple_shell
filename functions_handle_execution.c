#include "main.h"

void puts_error(char *command, char *shell_name, char *counter_as_str);
char *get_shell_name(void);

/**
 * handle_execution - Execute a command
 * @readed: The input string read
 * @run_counter: Pointer to a counter for executed commands
 *
 * Return: 0 on success, -1 on failure.
 */
ssize_t handle_execution(char **readed, size_t *run_counter)
{
	char *command = NULL, *command_path = NULL, *shell_name = NULL;
	char **commands = NULL, **command_argv = NULL, *counter = NULL;
	ssize_t builtin = -1, status = 0, i = 0;

	(*run_counter)++;

	commands = split(*readed, "\n");
	if (commands == NULL)
	{
		_free(readed);
		status = -1;
		return (status);
	}

	while (commands[i])
	{
		if (_spaces_ignore(commands[i]) == 0)
		{
			i++;
			continue;
		}
		command_argv = split(commands[i], " ");
		if (command_argv == NULL)
		{
			_free(readed);
			_free_arr(&commands);
			status = -1;
			return (status);
		}

		command = command_argv[0];

		builtin = is_builtin(command);
		if (builtin != -1)
		{
			_free(readed);
			_free_arr(&commands);
			_free_arr(&command_argv);
			status = builtin_handler(builtin);
			return (status);
		}

		command_path = search_path(command);
		if (command_path == NULL)
		{
			shell_name = get_shell_name();
			counter = number_to_string(*run_counter);
			puts_error(command, shell_name, counter);
			_free(readed);
			_free_arr(&commands);
			_free_arr(&command_argv);
			_free(&counter);
			status = 127;
			return (status);
		}

		status = execute_fork(command_path, command_argv);

		_free(&command_path);
		_free_arr(&command_argv);
		command = NULL;

		i++;
	}

	_free(readed);
	_free_arr(&commands);

	return (status);
}


/**
 * puts_error - puts error
 * @command: command
 * @shell_name: shell_name
 * @counter_as_str: counter_as_str
 * Return: void
 */
void puts_error(char *command, char *shell_name, char *counter_as_str)
{
	char *err_msg = malloc(1024);

	err_msg = _strncat(err_msg, shell_name, _strlen(shell_name));
	err_msg = _strncat(err_msg, ": ", _strlen(": "));
	err_msg = _strncat(err_msg, counter_as_str, _strlen(counter_as_str));
	err_msg = _strncat(err_msg, ": ", _strlen(": "));
	err_msg = _strncat(err_msg, command, _strlen(command));
	err_msg = _strncat(err_msg, ": ", _strlen(": "));
	err_msg = _strncat(err_msg, "not found\n", _strlen("not found\n"));
	_puts(err_msg, STDERR_FILENO);
	_free(&err_msg);
}


/**
 * get_shell_name - get_shell_name
 * Return: program name
 */
char *get_shell_name(void)
{
	size_t i = 0;
	char *shell_name = NULL;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], "_=", 2) == 0)
		{
			shell_name = environ[i] + 2;
		}
		i++;
	}
	return (shell_name);
}
