#include "0x1_main.h"

/**
 * execute_command -
 * @err_name:
 * @my_token:
 * @env:
*/
void execute_command(char *err_name, char **my_token, char *env[])
{
	char *path = NULL;
	int num_execve;

	/* Checks if the input starts with / */
	if (my_token[0][0] == '/')
	{
		execve(my_token[0], my_token, env);
	/* Prints error msg if execve() is not successdul / */
		pere_error(err_name, my_token, 2);
	}

	else
	{
		/* Stores the location of the inpt / */
		path = get_path(my_token[0]);

		if (path == NULL)
		{
			/* Print error msg if path is 0 and exit with 127 */
			pere_error(err_name, my_token, 3);
			exit(127);
		}

		/* Calls the execve() if path is not NULL*/
		num_execve = execve(path, my_token, env);
		if (num_execve == -1)
		{
			/* Print error msg if execve() is -1 and exit with 127 */
			pere_error(err_name, my_token, 3);
			exit(127);
		}
		
	}

}

