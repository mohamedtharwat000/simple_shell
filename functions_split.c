#include "main.h"


char **split_tok(char *str, char *delim, char ***words);

/**
 * split - Split a string into tokens using a delimiter
 * @str: The string to be split
 * @delim: The delimiter used to split the string
 *
 * Return: An array of strings representing the tokens,
 * or NULL on failure.
 */
char **split(char *str, char *delim)
{
	size_t count = 0;
	char **words = NULL;

	if (!str || !delim)
	{
		return (NULL);
	}

	count = count_tokens(str, delim);
	if (count == 0)
	{
		return (NULL);
	}

	words = malloc((count + 1) * sizeof(char *));
	if (!words)
	{
		return (NULL);
	}
	words = split_tok(str, delim, &words);
	if (!words)
	{
		_free_arr(&words);
		return (NULL);
	}

	return (words);
}



/**
 * split_tok - Split a string into tokens using a delimiter
 * @str: The string to be split
 * @delim: The delimiter used to split the string
 * @words: An array to store the tokens
 *
 * Return: The array of tokens.
 */
char **split_tok(char *str, char *delim, char ***words)
{
	size_t i = 0, start = 0, end = 0, length = 0, next_word = 0;
	size_t dlen = _strlen(delim);
	char *token = NULL;

	if (_strlen(delim) == 0)
	{
		while (str[i])
		{
			token = malloc(sizeof(char) + 1);
			if (!token)
			{
				return (NULL);
			}
			null_fill(token, sizeof(char) + 1);
			token[0] = str[i];
			token[1] = '\0';
			(*words)[i] = token;
			i++;
		}
		(*words)[i] = NULL;
		return (*words);
	}

	while (str[i])
	{
		if (_strncmp(&str[i], delim, dlen) == 0)
		{
			if (i != 0)
			{
				end = i;
				length = end - start;
				token = malloc(length + 1);
				if (!token)
				{
					return (NULL);
				}
				null_fill(token, length + 1);
				_strncpy(token, &str[start], length);
				token[length] = '\0';
				(*words)[next_word++] = token;
			}
			while (_strncmp(&str[i], delim, dlen) == 0)
			{
				i += dlen;
				start = i;
			}
			if (_strncmp(&str[i - dlen], delim, dlen) == 0)
			{
				continue;
			}
		}
		i++;
	}
	if (str[i] == '\0')
	{
		if (_strncmp(&str[i - dlen], delim, dlen) != 0)
		{
			end = i;
			length = end - start;
			token = malloc(length + 1);
			if (!token)
			{
				return (NULL);
			}
			null_fill(token, length + 1);
			_strncpy(token, &str[start], length);
			token[length] = '\0';
			(*words)[next_word++] = token;
		}
	}
	(*words)[next_word] = NULL;
	return (*words);
}
