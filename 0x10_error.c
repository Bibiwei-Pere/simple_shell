#include "0x1_main.h"

/**
 * pere_error -
 * @err_name:
 * @my_token:
 * @err_num:
 * Return:
*/
int pere_error(char *err_name, char **my_token, int err_num)
{
	static int i = 1;

	/* Loop to keep track of error number*/
	if (!err_num)
		i++;

	/* Prints the program name and error number to stderr*/
	if (err_num)
	{
		print_str(STDERR_FILENO, err_name);
		print_str(STDERR_FILENO, ": ");
		print_int(2, i);
	}

	/* Error message if fork() fails */
	if (err_num == 1)
	{
		print_str(STDERR_FILENO, ": ");
		print_str(STDERR_FILENO, my_token[0]);
		print_str(STDERR_FILENO, ": Fork Failed\n");
	}

	/* Error message if input starts with / and path is not found */
	if (err_num == 2)
	{
		print_str(STDERR_FILENO, ": ");
		print_str(STDERR_FILENO, my_token[0]);
		print_str(STDERR_FILENO, ": No such file or directory\n");
	}

	/* Error message for any other input that path is not found*/
	if (err_num == 3)
	{
		print_str(STDERR_FILENO, ": ");
		print_str(STDERR_FILENO, my_token[0]);
		print_str(STDERR_FILENO, ": not found\n");
	}

	return (EXIT_FAILURE);
}

