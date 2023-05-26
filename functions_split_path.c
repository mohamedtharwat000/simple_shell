#include "main.h"
/**
 * split_path - Split a string of paths into tokens
 * @path: The path string to split
 *
 * Return: An array of strings containing the individual path tokens,
 * or NULL if the input @path is NULL or empty.
 */
char **split_path(char *path)
{
	path += 5; /* Skip "PATH=" */

	return (split(path, ":"));
}
