#include "header_main.h"

/**
 * free_on_exit - frees user's typed command and linked list before exiting
 * @str: user's typed command
 * @env: input the linked list of envirnment
 */
void free_on_exit(char **str, env_list *env)
{
	free_string_2d(str);
	free_linked_list(env);
	_exit(0);
}
