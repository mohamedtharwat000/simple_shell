#include "header_main.h"

/**
 * free_linked_list - frees linked list
 * @list: linked list
 */
void free_linked_list(env_list *list)
{
	env_list *holder;

	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->var);
		free(holder);
	}

}
