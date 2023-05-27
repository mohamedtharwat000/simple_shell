#ifndef HEADERS_PROTOTYPES_H_INCLUDED
#define HEADERS_PROTOTYPES_H_INCLUDED

# define SIZE 1024
extern char **environ;

/* string functions */
size_t _strlen(const char *s);
size_t _strlength(const char *s);
char   *_strdup(const char *s1);
char   *_strchr(const char *s, int c);
char   *_strcat(char *s1, char *s2);
char   *_strjoin(char *s1, char *s2);
void   *_memcpy(void *dst, const void *src, size_t n);



char *_getline(int fd, global_t *global);
int  _strncmp(const char *s1, const char *s2, size_t n);
int  _atoi(char *s);
void _setenv(char **cmd, global_t *global);
void _unsetenv(char **cmd, global_t *global);
char *_itoa(int n);
int _puts(char *str, int fd, int new);
char *remove_comments(char *ptr, global_t *global, int fd);
void lstadd_back_env(env_t **lst, env_t *new);
void init_env(char **envp, global_t *global);
char *env_search(char	*str, global_t *global);
void lstadd_back_command(command_t **lst, command_t *new);
void lstadd_back_alias(alias_t **lst, alias_t *new);
char **split(char const *s, char c);
char *alias(char *ptr, global_t *global);
char *va_re(char *ptr, global_t *global);
void get_commands(char *ptr, global_t *global);
int  builtin_execute(char **args, global_t *global);
void executing(global_t *global);
int  puts_error(char *cmd, char *msg, global_t *global);
void env_print(char **cmd, global_t *global);
void cd(char **cmd, global_t *global);
void shell_exit(char **cmd, global_t *global);
void free_all(global_t *global);
void free_commands(global_t *global);
env_t *envsearch(char	*str, global_t *global);
void putnbr_fd(int n, int fd);
char *str_copy1(char	*str, int *index, char a);
char *alias_search(char	*str, global_t *global);
alias_t *search_alias(char	*str, global_t *global);
int is_lo_op(char *str);
char **advanced_split(char *str, global_t *global);
void exec_logical_operators(char **str, global_t *global);
char *get_path(char *str, global_t *global);
void exec_binary(command_t *command, global_t *global);
int is_new(char *str);
void _alias(char **cmd, global_t *global);
void help__alias(char **cmd, global_t *global);
void shell_exit(char **cmd, global_t *global);
int  is_num(char *str);
void _alias(char **cmd, global_t *global);

#endif
