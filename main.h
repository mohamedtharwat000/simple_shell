#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>


#define BUFFSIZE 1024
extern char **environ;

/* Main shell functions */
ssize_t shell(char **argv, char **envp);
ssize_t shell_interactive(char **argv, char **envp);
ssize_t shell_noninteractive(char **argv, char **envp);

/* Execute command function */
ssize_t handle_execution(char *readed, char **argv, char **envp,
												 int *run_counter);
ssize_t execute_fork(char *command_path, char **readed_argv, char **envp);

/* Path functions */
char *get_path(char **envp);
char **split_path(char *path);
char *search_path(char *command, char *path);

/* Read & write function */
ssize_t _getc(char *c, size_t fd);
ssize_t _putc(char c, size_t fd);
ssize_t _puts(char *str, size_t fd);
ssize_t _getline(char **buff, size_t *buff_size, FILE *fd);

/* String functions */
size_t _strlen(char *str);
char **split(char *str, char *delim);
char *_strncpy(char *dest, char *src, size_t n);
ssize_t _strncmp(char *str1, char *str2, size_t n);

/* Free allocated array of strings */
void free_strarr(char **str);


/* helper function */
char *numtostr(int num);
int string_to_number(char *str);

/**
 * struct builtin - Represents a built-in command
 * @command: The name of the built-in command
 * @handle_command: Pointer to the function that handles the command
 *
 */
typedef struct builtin
{
	char *command;
	ssize_t (*handle_command)(char *command);
} builtin;

ssize_t is_builtin(char *user_input);
ssize_t builtin_handler(char **readed_argv);

#endif
