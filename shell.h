#ifndef SIMPLE_SHEL
#define SIMPLE_SHEL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

/* shell functions */
int shell_cd(char **args);
int shell_ctrld(char **args);
int shell_exit(char **args);

/* get user input */
char *_getline(void);
char **_splitline(char *lineptr);

/* execute user input */
int _fork_exec(char **arg, char **av, char **env, char *line, int np, int c);

/* environment handle functions */
void _getenv(char **env);
char *_get_path(char **env);
int _splitline_path(char **arg, char **env);

/* string functions */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);

#endif
