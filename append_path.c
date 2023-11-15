#include "shell.h"

/**
* append_path - the fuction adds path to command
*
* @the_path: path to command
* @user_command: user entered command
* Return: on success returns a buffer containing command with a path 
* NULL on failure
*/

char *append_path(char *the_path, char *user_command)
{
	char *buff;
	size_t i = 0, j = 0;

	if (user_command == 0)
		user_command = "";

	if (the_path == 0)
		the_path = "";

	buff = malloc(sizeof(char) * (_strlen(the_path) + _strlen(user_command) + 2));
	if (!buff)
		return (NULL);

	while (the_path[i])
	{
		buff[i] = the_path[i];
		i++;
	}

	if (the_path[i - 1] != '/')
	{
		buff[i] = '/';
		i++;
	}
	while (user_command[j])
	{
		buff[i + j] = user_command[j];
		j++;
	}
	buff[i + j] = '\0';
	return (buff);
}
