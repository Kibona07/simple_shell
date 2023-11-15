#include "shell.h"

/**
* tokenizer - creates tokens from given input
* @line: to be tokenized
*
* Return: array of strings
*/

char **tokenizer(char *line)
{
	char *buff = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;

	buff = _strdup(line);
	if (!buff)
		return (NULL);
	bufp = buff;

	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buff, delim);

	while (token)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}

	tokens[index] = '\0';
	free(buff);
	return (tokens);
}
