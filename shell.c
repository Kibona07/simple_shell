#include "shell.h"

/**
* main - carries out the read, execute then print output loop
* @ac: argument count
* @av: argument vector
* @envp: environment vector
*
* Return: 0
*/

int main(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **user_command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);

	while (1)
	{
		free_buffers(user_command);
		free_buffers(paths);
		free(pathcommand);
		prompt_user();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		user_command = tokenizer(line);

		if (user_command == NULL || *user_command == NULL || **user_command == '\0')
			continue;
		if (checker(user_command, line))
			continue;
		path = find_path();
		paths = tokenizer(path);
		pathcommand = test_path(paths, user_command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			executing(pathcommand, user_command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
