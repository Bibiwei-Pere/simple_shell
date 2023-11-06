#include "0x1_main.h"

/**
 * main - Entry point for my Shell program
 * @c: Counts arguments but typecasted (not used) for now
 * @argv: Argument variable, gets the name of my shell
 *        program for use in my error function
 * Return: Always 0 (Success), my Shell is perfect
 */
int main(int c, char **argv)
{
	size_t buffsize = 0;
	char *buffer = NULL, *my_token[1], *program_name = argv[0];
	(void)c;

	while (1)
	{
		/* Checks if its Interactive mode */
		if (isatty(STDIN_FILENO))
			print_str(STDOUT_FILENO, "$ ");

		/* Collects Input from Users */
		_getline(&buffer, &buffsize);

		/* Splits Inputs into tokens */
		tokenize(buffer, my_token);
		if (my_token[0] == NULL)
			continue;

		/* Create Child Process */
		_fork(program_name, my_token);

		/* Handles the loop in pere_error() */
		pere_error(program_name, NULL, 0);
	}
	free(buffer);

	return (0);
}

