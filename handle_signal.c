#include "shell.h"

/**
 *handle_signal - keeps track that it is interactive mode
 *@mm: the signal number
 *Return: nothing to return
 */

void handle_signal(int mm)
{
	(void)mm;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$", 2);
}
