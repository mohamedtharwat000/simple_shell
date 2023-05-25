#include "header_main.h"

/**
 * handle_which - handle which builtin
 * @str: string
 * @env: environmental variable
 * Return: fleshed out command copy
 */
char *handle_which(char *str, env_list *env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0;


	pth = get_env("PATH", env);
	toks = handle_str_tok(pth, ":");
	free(pth);

	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			free_string_2d(toks);
			return (cat);
		}
		free(cat);
		i++;
	}
	free_string_2d(toks);
	return (str);
}
