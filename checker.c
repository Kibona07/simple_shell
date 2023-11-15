#include "shell.h"

/**
 *checker - checks to see if it is a built in function
 *@cmd: a tokenized user input
 *@buff: line driven from getline function
 *
 *Return: 1 if cmd gets excuted and 0 if cmd is not executed
 */

int checker(char **cmd, char *buff)
{
	if (handle_builtin(cmd, buff))
		return (1);

	else if (**cmd == '/')
	{
		executing(cmd[0], cmd);
		return (1);
	}
	return (0);
}
