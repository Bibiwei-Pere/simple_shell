#include "0x1_main.h"

/**
 * tokenize - Splits input or buffer into tokens
 *            (commands and arguments) using _strtok()
 * @buffer: Input
 * @my_token: Store the address of the tokens (commands and arguments)
 */
void tokenize(char *buffer, char **my_token)
{
	int j = 0;

	my_token[j] = _strtok(buffer, " \n");

	while (my_token[j])
		my_token[++j] = _strtok(NULL, " \n");

	my_token[j] = NULL;
}

