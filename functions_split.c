#include "main.h"

size_t count_tokens(char *str, char *delim);
char **split_tok(char *str, char *delim, char **words);

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

	words = split_tok(str, delim, words);
	if (!words)
	{

		return (NULL);
	}

	words[count] = NULL;

	return (words);
}

/**
 * count_tokens - Count the number of tokens in a string using a delimiter
 * @str: The string to be counted
 * @delim: The delimiter used to count the tokens
 *
 * Return: The count of tokens found in the string.
 */
size_t count_tokens(char *str, char *delim)
{
	size_t i = 0, count = 0, dlen = _strlen(delim);

	if (_strlen(str) == 0)
	{
		return (count);
	}

	while (str[i])
	{
		if (_strncmp(&str[i], delim, dlen) == 0)
		{
			if (i != 0)
			{
				count++;
			}
			while (_strncmp(&str[i], delim, dlen) == 0)
			{
				i += dlen;
			}
			if (_strncmp(&str[i - dlen], delim, dlen) == 0)
			{
				i--;
			}
		}
		i++;
	}
	if (str[i] == '\0')
	{
		if (_strncmp(&str[i - dlen], delim, dlen) != 0)
		{
			count++;
		}
	}

	return (count);
}

/**
 * split_tok - Split a string into tokens using a delimiter
 * @str: The string to be split
 * @delim: The delimiter used to split the string
 * @words: An array to store the tokens
 *
 * Return: The array of tokens.
 */
char **split_tok(char *str, char *delim, char **words)
{
	size_t i = 0, start = 0, end = 0, length = 0, next_word = 0;
	size_t dlen = _strlen(delim);
	char *token = NULL;


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
					free_strarr(words);
					return (NULL);
				}
				_strncpy(token, &str[start], length);
				token[length] = '\0';
				words[next_word++] = token;
				start = end;
			}
			while (_strncmp(&str[i], delim, dlen) == 0)
			{
				i += dlen;
			}
			start = i;
			if (_strncmp(&str[i - dlen], delim, dlen) == 0)
			{
				i--;
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
				free_strarr(words);
				return (NULL);
			}
			_strncpy(token, &str[start], length);
			token[length] = '\0';
			words[next_word++] = token;
		}
	}

	if (next_word == 0)
	{
		free_strarr(words);
		return (NULL);
	}

	return (words);
}
