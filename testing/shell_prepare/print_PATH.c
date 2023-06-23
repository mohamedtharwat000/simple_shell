#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int _strncmp(char *str1, char *str2, int n);

int main(int ac, char **av, char **env)
{
	char *str;
	int i = 0, j = 0, start = 0, end = 0, len;

	(void)ac;
	(void)av;

	while (env[i] != NULL)
	{
		if (_strncmp(env[i], "PATH", 4) == 0)
		{
			printf("%s\n", env[i]);
			for (; env[i][j] != '\0'; j++)
			{
				if (env[i][j] == '=')
				{
					start = j + 1;
				}
				if (env[i][j] == ':')
				{
					end = j;
					len = end - start;
					str = malloc(len);
					strncpy(str, &env[i][start], len);
					str = strcat(str, "/sh");
					if (access(str, F_OK) == 0)
					{
						printf("%s\n", str);
						return (0);
					}
					else
					{
						printf("%d\n", errno);
					}
					free(str);
					start = j + 1;
				}
			}
		}
		i++;
	}
	return (1);
}


int _strncmp(char *str1, char *str2, int n)
{
	int i;

	if (!str1 || !str2 || n < 0)
	{
		return (-1);
	}

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
	}

	return 0;
}
