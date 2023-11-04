#include "0x1_main.h"

/**
 * exit_shell -
 * @buffer:
 * Return:
*/
int exit_shell(char *buffer)
{
	if (_strncmp(buffer, "exit", 4) == 0)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	return (0);
}

