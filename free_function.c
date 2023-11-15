#include "shell.h"

/**
* free_buffers - frees buffers
* @buff: buffer to be freed
*
* Return: no return
*/

void free_buffers(char **buff)
{
	int i = 0;

	if (!buff || buff == NULL)
		return;

	while (buff[i])
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}
