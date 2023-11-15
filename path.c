#include "shell.h"

/**
* find_path - finds the path from the global enviroment
* Return: NULL whether path is not found or found.
*/
char *find_path(void)
{
	int x;
	char **envn = environ, *path = NULL;

	while (*envn)
	{
		if (_strncmp(*envn, "PATH=", 5) == 0)
		{
			path = *envn;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		envn++;
	}
	return (NULL);
}
