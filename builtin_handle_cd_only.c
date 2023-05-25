#include "header_main.h"


/**
 * handle_cd_only - cd -> /home
 * @env: environmental linked list
 * @current: current working directotry
 */
void handle_cd_only(env_list *env, char *current)
{
	char *home = NULL;

	home = get_env("HOME", env);
	handle_c_setenv(&env, "OLDPWD", current);
	free(current);
	if (access(home, F_OK) == 0)
	{
		chdir(home);
	}
	current = NULL;
	current = getcwd(current, 0);
	handle_c_setenv(&env, "PWD", current);
	free(current);
	free(home);
}
