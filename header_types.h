#ifndef HEADER_STRUCT_H
#define HEADER_STRUCT_H

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} env_list;

#endif
