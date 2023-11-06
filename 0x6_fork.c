#include "0x1_main.h"

/**
 * _fork - Creates child process (CP) and call execute_command() if CP == 0
 * @program_name: Name of Shell program after compiling (./hsh, ./a.out etc)
 * @my_token: Stores the address of the input
 */
void _fork(char *program_name, char **my_token)
{
	pid_t child_pid;
	int exit_status, status_code;

	/* Creates child process */
	child_pid = fork();

	/* Exit shell when called */
	exit_shell(my_token[0]);

	/* Exits if fork fails (-1) */
	if (child_pid == -1)
	{
		pere_error(program_name, my_token, 1);
		exit(EXIT_FAILURE);
	}

	/* Calls execute_commmand() if fork is successful (0)*/
	else if (child_pid == 0)
		execute_command(program_name, my_token);

	else
	{
		/* Wait for child process to end before Parent process continues */
		wait(&exit_status);

		/* Checks if there's no error and exit with status */
		if (WIFEXITED(exit_status) != 0)
		{
			status_code = WEXITSTATUS(exit_status);

			if (status_code == 127)
				exit(127);
			if (status_code == 2)
				exit(2);
		}
	}
}

