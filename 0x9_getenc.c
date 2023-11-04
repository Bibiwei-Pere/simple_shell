#include "0x1_main.h"

/**
 * _getenv -
 * @i:
 * @buffer:
 * @env:
 * Return:
*/
char *_getenv(const char* buffer) 
{
	int buf_len = strlen(buffer);
	int i = 0;

	while (environ[i] != NULL)
	{
	        if (strncmp(environ[i], buffer, buf_len) == 0 && environ[i][buf_len] == '=')
		{
			return (environ[i] + buf_len + 1);
		}
		i++;
	}

	return NULL;
}

