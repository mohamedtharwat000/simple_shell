#include "main.h"

/**
 * _getc - Reads a character from a file descriptor
 * @c: Pointer to a character variable to store the read character
 * @fd: File descriptor from which to read the character
 *
 * Return: On success, returns the number of bytes read,
 * On error or end-of-file condition, returns -1.
 */
ssize_t _getc(char *c, size_t fd)
{
	return (read(fd, c, sizeof(*c)));
}
