#include "0x1_main.h"

/**
 * main -
 * @c:
 * @argv:
 * @env:
 * Return:
*/
int main(int c, char **argv)
{
	ssize_t num_char;
	size_t buffsize = 0;
	char *buffer = NULL, *my_token[1], *err_name = argv[0];
	(void)c;

	while (1)
	{
		/* Checks if its Interactive mode */
		if (isatty(STDIN_FILENO))
			print_str(STDOUT_FILENO, "$ ");

		/* Collects Input from Users & handles EOF */
		num_char = getline(&buffer, &buffsize, stdin);
		if (num_char == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		/* Splits Inputs into tokens */
		tokenize(buffer, my_token);
		if (my_token[0] == NULL)
			continue;

		/* Create Child Process */
		_fork(err_name, my_token, environ);

		/* Handles the loop in pere_error() */
		pere_error(err_name, NULL, 0);
	}
	free(buffer);

	return (0);
}

