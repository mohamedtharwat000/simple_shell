#include "main.h"

/**
 * _putc - Write a character to the standard output
 * @c: The character to be written
 * @fd: file descriptor represent the output.
 *
 * Return: On success, it returns the number of characters written (1).
 * On failure, it returns -1 and sets the errno variable appropriately.
 *
 */
ssize_t _putc(char c, size_t fd)
{
	return (write(fd, &c, sizeof(c)));
}
