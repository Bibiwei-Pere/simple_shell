#include "0x1_main.h"

/**
 * execute_command - Process the inputs and produce output. Called in _fork()
 * @program_name: Name of Shell program after compiling (./hsh, ./a.out etc)
 * @my_token: Stores the address of the input
 */
void execute_command(char *program_name, char **my_token)
{
	char *path = NULL;
	int num_execve;

	/* Checks if the input starts with / */
	if (my_token[0][0] == '/')
	{
		execve(my_token[0], my_token, environ);
		/* Prints error msg if execve() is not successdul / */
		pere_error(program_name, my_token, 2);
	}

	else
	{
		/* Stores the location of the inpt / */
		path = get_path(my_token[0]);

		if (path == NULL)
		{
			/* Print error msg if path is 0 and exit with 127 */
			pere_error(program_name, my_token, 3);
			exit(127);
		}

		/* Calls the execve() if path is not NULL*/
		num_execve = execve(path, my_token, environ);
		if (num_execve == -1)
		{
			/* Print error msg if execve() is -1 and exit with 127 */
			pere_error(program_name, my_token, 3);
			exit(127);
		}
	}
}

