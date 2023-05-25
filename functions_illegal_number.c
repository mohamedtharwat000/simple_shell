
#include "header_main.h"

/**
 * illegal_number - write error ("sh: 3: exit: Illegal number abc (or -1)")
 * @str: user's typed argument after the cmd exit
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void illegal_number(char *str, int c_n, env_list *env)
{
	int count = 0;
	char *shell = NULL, *num = NULL;

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
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, "\n", 1);
}
