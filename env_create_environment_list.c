#include "header_main.h"

/**
 * env_linked_list - creates a linked list from environmental variables
 * @env: environmental variables
 * Return: linked list
 */
env_list *env_linked_list(char **env)
{
	env_list *head;
	ssize_t i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		handle_add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}
