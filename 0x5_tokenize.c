#include "0x1_main.h"

/**
 * tokenize -
 * @buffer:
 * @my_token:
*/
void tokenize(char *buffer, char **my_token)
{
	int j = 0;

	my_token[j] = strtok(buffer, " \n");
	while (my_token[j])
	{
		my_token[++j] = strtok(NULL, " \n");
	}
	my_token[j] = NULL;
}

