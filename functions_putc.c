#include "main.h"

/**
 * _putc - Write a character to the standard output
 * @c: The character to be written
 *
 * This function writes a single character @c to the standard output.
 *
 * @c: The character to be written.
 *
 * Return: On success, it returns the number of characters written (1).
 * On failure, it returns -1 and sets the errno variable appropriately.
 *
 * Note: This function writes to the standard output (stdout), which is
 * typically the console or the terminal.
 */
ssize_t _putc(char c, size_t fd)
{
	return (write(fd, &c, sizeof(c)));
}
