#ifndef HEADERS_TYPES_H_INCLUDED
#define HEADERS_TYPES_H_INCLUDED

/* user defined types */

/**
 * struct command_s - singly linked list
 * @path: the path.
 * @args: the args.
 * @tmp: the tmp.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for command.
 */
typedef struct command_s
{
	char		        *path;
	char		        **args;
	char				*tmp;
	struct command_s	*next;
} command_t;

/**
 * struct alias_s - singly linked list
 * @name: the nmae.
 * @value: the value.
 * @next: points to the next node.
 *
 * Description: singly linked list node structure
 * for alias.
 */
typedef struct alias_s
{
	char		    *name;
	char		    *value;
	struct alias_s	*next;
} alias_t;

/**
 * struct env_s - singly linked list
 * @name: the name.
 * @value: the value.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for env.
 */
typedef struct env_s
{
	char		    *name;
	char		    *value;
	struct env_s	*next;
} env_t;

/**
 * struct global_s - global variable.
 * @commands: the commands.
 * @env: the env.
 * @alias: the alias.
 * @exit_code: the exit code.
 * @pid: the pid.
 * @name: the name.
 * @envp: the envp.
 * @cmd: the cmd.
 * @left: the left.
 * @n: the line num.
 * @fd: the fd.
 *
 * Description: global variable.
 */
typedef struct global_s
{
	command_t   *commands;
	env_t       *env;
	alias_t     *alias;
	int		    exit_code;
	pid_t       pid;
	char        *name;
	char        **envp;
	char		*cmd;
	char		*left;
	int			n;
	int			fd;
} global_t;


#endif
