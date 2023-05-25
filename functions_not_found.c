#include "header_main.h"

/**
 * not_found - write error ("sh: 1: lss: not found")
 * @str: user's typed command
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void not_found(char *str, int c_n, env_list *env)
{
	int count = 0;
	char *shell, *num;

	shell = get_env("_", env);
	while (shell[count] != '\0')
	{
		count++;
	}
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = _itoa(c_n);
	count = 0;
	while (num[count] != '\0')
	{
		count++;
	}
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}
