#include "shell.h"

/**
* handle_builtin - handles execution of builtin functions
* @user_command: a tokenized command
* @line: input read from stdin
* Return: 1 if executed and 0 if not executed
*/

int handle_builtin(char **user_command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*user_command, builtin.env) == 0)
	{
		print_envn();
		return (1);
	}

	else if (_strcmp(*user_command, builtin.exit) == 0)
	{
		exit_command(user_command, line);
		return (1);
	}
	return (0);
}
