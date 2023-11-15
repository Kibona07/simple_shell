#include "shell.h"

/**
* exit_command - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/

void exit_command(char **user_command, char *line)
{
	free(line);
	free_buffers(user_command);
	exit(0);
}
