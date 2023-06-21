#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define BUFFSIZE 1024
extern char **argv;
extern char **environ;

/* Main shell functions */
ssize_t shell(void);
ssize_t shell_interactive(void);
ssize_t shell_noninteractive(void);

/* Execute command function */
ssize_t handle_execution(char **readed, size_t *counter);
ssize_t execute_fork(char *command_path, char **readed_argv);

/* Path functions */
char *get_path(void);
char *search_path(char *command);

/* Read & write function */
ssize_t _getc(char *c, size_t fd);
ssize_t _putc(char c, size_t fd);
ssize_t _puts(char *str, size_t fd);
ssize_t _getline(char **buff, size_t *buff_size, FILE *fd);

/* String functions */
size_t _strlen(char *str);
char **split(char *str, char *delim);
size_t count_tokens(char *str, char *delim);
char *_strncpy(char *dest, char *src, size_t n);
char *_strncat(char *dest, char *src, size_t n);
ssize_t _strncmp(char *str1, char *str2, size_t n);

/* Free allocated array of strings */
void _free(char **str);
void _free_arr(char ***arr);

/* helper function */
char *number_to_string(int num);
int string_to_number(char *str);
void null_fill(char *mem, size_t size);
ssize_t _spaces_ignore(char *str);

/**
 * struct builtin_struct - Represents a built-in command
 * @command: The name of the built-in command
 * @handle_command: Pointer to the function that handles the command
 *
 */
typedef struct builtin_struct
{
	char *command;
	ssize_t (*handle_command)(void);
} builtin_t;

ssize_t is_builtin(char *command);
ssize_t builtin_handler(ssize_t builtin);

#endif
