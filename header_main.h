#ifndef SHELL
#define SHELL

#include "header_lib.h"
#include "header_types.h"

/* constants */
#define BUFFSIZE 1024

/* main functions */
int Shell_start(char **env);
size_t get_line(char **str);
void handle_non_interactive(env_list *env);
char *ignore_space(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _execve(char *argv[], env_list *env, int num);
void free_string_2d(char **str);
void not_found(char *str, int num, env_list *env);
void illegal_number(char *str, int c_n, env_list *env);

/* string functions */
char **_string_tokens(char *str, char *delm);
char **handle_str_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int token_strlen(char *str, int pos, char delm);
char *handle_strcat(char *dest, char *src);
char *handle_str_duplicate(char *str, int cs);
int handle_token_size(char *str, char delm);
int token_strlen(char *str, int pos, char delm);
int token_size(char *str, char delm);
char *ignore_delm(char *str, char delm);


/* environment functions */
void free_linked_list(env_list *list);
int print_env(char **str, env_list *env);
char *get_env(char *str, env_list *env);
env_list *env_linked_list(char **env);
env_list *handle_add_end_node(env_list **head, char *str);
size_t print_list(env_list *h);
int delete_nodeint_at_index(env_list **head, int index);
int find_env(env_list *env, char *str);
env_list *env_linked_list(char **env);
size_t print_list(env_list *h);
void free_linked_list(env_list *list);
env_list *handle_add_end_node(env_list **head, char *str);
int handle_unsetenv(env_list **env, char **str);
int handle_setenv(env_list **env, char **str);
int handle_c_setenv(env_list **env, char *name, char *dir);

/* built_in functions */
char *handle_which(char *str, env_list *env);
int handle_exit(char **s, env_list *env, int num, char **command);
int handle_cd(char **str, env_list *env, int num);
int handle_built_in(char **token, env_list *env, int num, char **command);
void cant_cd_to(char *str, int c_n, env_list *env);
void handle_cd_only(env_list *env, char *current);
int handle_cd_execute(env_list *env, char *current,
											 char *dir, char *str, int num);


/* helper functions */
int _atoi(char *s);
char *_itoa(int num);
void handle_ctrlC(int n);
char *ignore_spaces(char *str);
char *ignore_space(char *str);
void handle_ctrlD(int i, char *command, env_list *env);
void free_on_exit(char **str, env_list *env);
int numlen(int n);
void not_found(char *str, int c_n, env_list *env);
void illegal_number(char *str, int c_n, env_list *env);

#endif
