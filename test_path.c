#include "shell.h"

/**
* test_path - checks whether path is valid
* @path: tokenized path
* @user_command: user entered command
*
* Return: path appended with user_command on success
* NULL on failure
*/

char *test_path(char **path, char *user_command)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = appending_path(path[i], user_command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
