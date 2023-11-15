#include "shell.h"

/**
 * executing - executes commands entered by users
 *@ucp: command
 *@cmd:vector array of pointers to commands
 *
 * Return: 0 on success
 */

void executing(char *ucp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **envn = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(ucp);

	if (child_pid == 0)
	{
		execve(ucp, cmd, envn);
		perror(ucp);
		free(ucp);
		free_buffers(cmd);
		exit(98);
	}

	else
		wait(&status);
}
