#include "0x1_main.h"

/**
 * get_path - Gets the normal path from the environment variable
 * @command: String entered from the terminal
 * Return: NULL
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
 * @command: Pointer to store the input received
 * Return: NULL
*/
char *path_location(char *my_path, char *command)
{
	char *path_token, *file_path;

	path_token = strtok(my_path, ":");
	file_path = malloc(_strlen(command) + _strlen(my_path) + 2);

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
		}

		path_token = strtok(NULL, ":");
	}

	free(file_path);

	return (NULL);
}

