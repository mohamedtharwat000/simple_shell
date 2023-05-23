#include "main.h"

char **split_path(char *path)
{
	char **path_tokens;

	path += 5; /* Skip "PATH=" */
	path_tokens = split(path, ":");

	return (path_tokens);
}