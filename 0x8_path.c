#include "0x1_main.h"

/**
 * get_path - Gets the PATH from the environment variable using _getenv().
 *            Called in execute_command()
 * @command: Inputs or string entered
 * Return: Always new_path else NULL if successful
 */
char *get_path(char *command)
{
	char *my_path, *new_path;

	my_path = _getenv("PATH");

	if (my_path)
	{
		new_path = path_location(my_path, command);
		return (new_path);
	}

	return (NULL);
}

/**
 * path_location - Gets the path of my current working directory
 * @my_path: Pointer to store the path
 * @command: Inputs
 * Return: Always file_path else NULL if successful
 */
char *path_location(char *my_path, char *command)
{
	char *path_token, *file_path, *my_path_cpy;

	my_path_cpy = _strdup(my_path);
	path_token = _strtok(my_path_cpy, ":");
	file_path = malloc(_strlen(command) + _strlen(my_path_cpy) + 2);

	while (path_token != NULL)
	{
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, command);
		_strcat(file_path, "\0");

		if (access(file_path, X_OK) == 0)
		{
			return (file_path);
			free(file_path);
			free(my_path_cpy);
		}

		path_token = _strtok(NULL, ":");
	}

	free(file_path);
	free(my_path_cpy);

	return (NULL);
}

