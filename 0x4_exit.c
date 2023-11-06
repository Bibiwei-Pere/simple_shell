#include "0x1_main.h"

/**
 * exit_shell - Exit Shell program. Called in _fork()
 *              after creating a child process.
 * @buffer: Input
 * Return: Always 0 if successful
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

