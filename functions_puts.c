#include "main.h"

/**
 * _puts - Write a string to the standard output
 * @str: The string to be written
 *
 * This function writes the null-terminated string @str to the standard output.
 *
 * @str: The string to be written.
 *
 * Return: On success, it returns the number of characters written.
 * On failure, it returns -1 and sets the errno variable appropriately.
 *
 * Note: This function writes to the standard output (stdout), which is
 * typically the console or the terminal.
 */
ssize_t _puts(char *str, size_t fd)
{
	return (write(fd, str, _strlen(str)));
}
