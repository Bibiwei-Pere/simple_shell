#include "0x1_main.h"

/**
 * print_str - Prints Inputs (strings) to stdout if fd is 1 else stderr
 * @file_desc: 1 for stdout, >2 for stderr
 * @buffer: Input or string
 * Return: Always 0 if successful
 */
int print_str(int file_desc, char *buffer)
{
	if (file_desc == 1)
		write(STDOUT_FILENO, buffer, _strlen(buffer));
	else
		write(STDERR_FILENO, buffer, _strlen(buffer));

	return (0);
}
/**
 * print_int - Prints Inputs (integer) to stdout if fd is 1 else stderr
 * @file_desc: 1 for stdout, >2 for stderr
 * @n: Input or integer
 * Return: Always 0 if successful
 */
int print_int(int file_desc, int n)
{
	char str;

	/* Prints integer when n is > 9 */
	if (n >= 10)
		return (print_int(file_desc, n / 10) + print_int(file_desc, n % 10));

	str = '0' + n;

	if (file_desc == 1)
		return (print_str(STDOUT_FILENO, &str));

	return (print_str(STDERR_FILENO, &str));
}

