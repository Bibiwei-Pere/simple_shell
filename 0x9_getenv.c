#include "0x1_main.h"

/**
 * _getenv - Collects any environment variable
 * @buffer: Input
 * Return: Environ if successful else NULL
 */
char *_getenv(char *buffer)
{
	int buf_len = _strlen(buffer);
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], buffer, buf_len) == 0 && environ[i][buf_len] == '=')
		{
			return (environ[i] + buf_len + 1);
		}
		i++;
	}

	return (NULL);
}

