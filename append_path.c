#include "shell.h"

/**
* appending_path - the fuction adds path to command
*
* @path: path to command
* @user_command: user entered command
* Return: on success returns a buffer containing command with a path
* NULL on failure
*/

char *appending_path(char *path, char *user_command)
{
	char *buff;
	size_t i = 0, j = 0;

	if (user_command == 0)
		user_command = "";

	if (path == 0)
		path = "";

	buff = malloc(sizeof(char) * (_strlen(path) + _strlen(user_command) + 2));
	if (!buff)
		return (NULL);

	while (path[i])
	{
		buff[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
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
