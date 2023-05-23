#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define BUFFSIZE 1024

/* Main shell functions */
ssize_t interactive_shell(char **argv, char **envp);
ssize_t non_interactive_shell(char **argv, char **envp);

/* Execute command function */
int exec_buff(char *command, char **comand_argv, size_t *counter, char **argv, char **envp);

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

/* Builtin commands struct */
typedef struct
{
	char *command;
	int (*handle_command)(char *command);
} builtin;


#endif
