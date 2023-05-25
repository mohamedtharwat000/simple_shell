#include "header_main.h"

/**
 * handle_add_end_node - add node to end of linked list
 * @head: head of linked list
 * @str: new node data
 * Return: pointer to new linked list
 */
env_list *handle_add_end_node(env_list **head, char *str)
{
	env_list *new;
	env_list *holder;

	if (head == NULL || str == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(env_list));
	if (new == NULL)
		return (NULL);

	new->var = _strdup(str);
	new->next = NULL;

	holder = *head;
	if (holder != NULL)
	{
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}
