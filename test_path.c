#include "shell.h"

/**
* test_path - checks whether path is valid
* @the_path: tokenized path
* @user_command: user entered command
*
* Return: the_path appended with user_command on success
* NULL on failure
*/

char *test_path(char **the_path, char *user_command)
{
	int i = 0;
	char *output;

	while (the_path[i])
	{
		output = append_path(the_path[i], user_command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
