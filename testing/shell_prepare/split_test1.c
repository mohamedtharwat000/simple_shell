#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t count_tokens(char *str, char *delim);
char **split_tok(char *str, char *delim, char **words);

char **split(char *str, char *delim) {
  size_t count = 0;
  char **words = NULL;

  if (!str || !delim) {
    return NULL;
  }

  count = count_tokens(str, delim);
  if (count == 0) {
    return NULL;
  }

  words = malloc((count + 1) * sizeof(char *));
  if (!words) {
    return NULL;
  }

  words = split_tok(str, delim, words);
  if (!words) {
    return NULL;
  }

  words[count] = NULL;

  return words;
}

size_t count_tokens(char *str, char *delim) {
  size_t position = 0, count = 0, dlen = strlen(delim);

  while (str[position]) {
    if (strncmp(&str[position], delim, dlen) == 0) {
      if (position != 0) {
        count++;
      }
      while (strncmp(&str[position], delim, dlen) == 0) {
        position += dlen;
      }
    }

    if (str[position] == '\0') {
      if (strncmp(&str[position - dlen], delim, dlen) != 0) {
        count++;
      }
      break;
    }

    position++;
  }
  return count;
}

char **split_tok(char *str, char *delim, char **words) {
  size_t position = 0, start = 0, end = 0, length = 0, next_word = 0;
  size_t dlen = strlen(delim);
  char *token = NULL;

  while (str[position]) {
    if (strncmp(&str[position], delim, dlen) == 0) {
      if (position != 0) {
        end = position;
        length = end - start;
        token = malloc(length + 1);
        if (!token) {
          return NULL;
        }
        strncpy(token, &str[start], length);
        token[length] = '\0';
        words[next_word++] = token;
        start = end + dlen;
      }
      while (strncmp(&str[position], delim, dlen) == 0) {
        position += dlen;
      }
      start = position;
    }

    if (str[position] == '\0') {
      if (strncmp(&str[position - dlen], delim, dlen) != 0) {
        end = position;
        length = end - start;
        token = malloc(length + 1);
        if (!token) {
          return NULL;
        }
        strncpy(token, &str[start], length);
        token[length] = '\0';
        words[next_word++] = token;
        start = end + dlen;
      }
      break;
    }

    position++;
  }

  if (next_word == 0) {
    return NULL;
  }

  return words;
}

int main() {
  int i;
  char *delim = " ", *str = "    1   2    3   4  ";
  size_t count = count_tokens(str, delim);
  char **tokens = split(str, delim);
  printf("%lu \n", count);
  for (i = 0; tokens[i]; i++) {
    printf("token: %s \n", tokens[i]);
    free(tokens[i]);
  }
  free(tokens);

  return 0;
}
