#include "main.h"

/**
 * _puts - Write a string to the standard output
 * @str: The string to be written
 * @fd: file descriptor represent the output.
 *
 * Return: On success, it returns the number of characters written.
 * On failure, it returns -1 and sets the errno variable appropriately.
 *
 */
ssize_t _puts(char *str, size_t fd)
{
	return (write(fd, str, _strlen(str)));
}
