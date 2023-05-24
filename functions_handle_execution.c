#include "main.h"

void puts_onerror(char *shell_name, char *err_num);

/**
 * handle_execution - Execute a command
 * @readed: The input string read
 * @argv: The command-line arguments
 * @envp: The environment variables
 * @run_counter: Pointer to a counter for executed commands
 *
 * Return: 0 on success, -1 on failure.
 */
ssize_t handle_execution(char *readed, char **argv, char **envp,
												 int *run_counter)
{
	ssize_t status = 0;
	char *path = NULL, *command_path = NULL, **readed_argv = NULL, *err_num;

	(*run_counter)++;
	readed_argv = split(readed, " ");
	if (readed_argv == NULL)
		return (-1);
	path = get_path(envp);
	if (path == NULL)
	{
		free_strarr(readed_argv);
		return (-1);
	}
	command_path = search_path(readed_argv[0], path);
	if (command_path == NULL)
	{
		if (is_builtin(readed_argv[0]) == 0)
		{
			status = builtin_handler(readed_argv);
			free_strarr(readed_argv);
			return (status);
		}
		else
		{
			err_num = numtostr(*run_counter);
			puts_onerror(argv[0], err_num);
			free_strarr(readed_argv);
			free(err_num);
			return (-1);
		}
	}
	else
	{
		status = execute_fork(command_path, readed_argv, envp);
		free(command_path);
		free_strarr(readed_argv);
	}
	return (status);
}


/**
 * puts_onerror - puts error
 * @shell_name: shell_name
 * @err_num: err_num
 * Return: void
 */
void puts_onerror(char *shell_name, char *err_num)
{
	_puts(shell_name, STDOUT_FILENO);
	_puts(": ", STDOUT_FILENO);
	_puts(err_num, STDOUT_FILENO);
	_puts(": ", STDOUT_FILENO);
}
