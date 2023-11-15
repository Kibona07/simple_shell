#include "shell.h"

/**
* print_envn - prints the environment string to stdout
* Return: 0
*/
void print_envn(void)
{
	int x = 0;
	char **envn = environ;

	while (envn[x])
	{
		write(STDOUT_FILENO, (const void *)envn[x], _strlen(envn[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
