#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 0, count = 0;
	char str[] = ",,,,apple,,banana,cherry,date,test,,";
	char delim[] = ",";
	char *token;
	char **words;
	char *strtmp;

	strtmp = malloc(strlen(str));
	if (!strtmp)
	{
		return (-1);
	}
	strcpy(strtmp, str);
	token = strtok(strtmp, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(strtmp);

	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (-1);
	}
	words[count] = NULL;

	token = strtok(str, delim);
	while (token != NULL)
	{
		words[i] = malloc((strlen(token) + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			return (-1);
		}

		strcpy(words[i], token);
		words[i][strlen(token)] = '\0';

		i++;
		token = strtok(NULL, delim);
	}

	for (i = 0; words[i]; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);
	return (0);
}
