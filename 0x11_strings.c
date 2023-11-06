#include "0x1_main.h"

/**
 * _strlen - Gets the length or size of the input.
 *           Used in print_str() & path_location()
 * @buffer: Input
 * Return: Length or size (i)
 */
int _strlen(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strncmp - Compares input with a specified length of string.
 *            Used in exit() & _getenv()
 * @destination: Input
 * @source: Specified string
 * @num: Length or size of string
 * Return: Always 0 if successful
 */
int _strncmp(const char *destination, char *source, int num)
{
	while (num && *destination == *source)
	{
		num--;
		destination++;
		source++;
	}
	if (num)
		return (*destination - *source);

	return (0);
}

/**
 * _strcpy - Copies a string to another location. Used in path_location()
 * @destination: New location
 * @source: Previous location
 * Return: New location if successful
 */
char *_strcpy(char *destination, char *source)
{
	int j;

	j = 0;
	while (source[j] != '\0')
	{
		destination[j] = source[j];
		j++;
	}
	destination[j] = '\0';

	return (destination);
}

/**
 * _strcat - Adds two strings together. Used in path_location()
 * @destination: First string
 * @source: Second string
 * Return: First string if successful
 */
char *_strcat(char *destination, char *source)
{
	int k, l;

	k = 0;
	l = 0;
	while (destination[k] != '\0')
	{
		k++;
	}
	destination[k] = ' ';
	while (source[l] != '\0')
	{
		destination[k] = source[l];
		k++;
		l++;
	}
	destination[k] = '\0';

	return (destination);
}

/**
 * _strdup - Copies an input or string to another location
 * @buffer: Input
 * Return: Poiter (new_str) that stores the address of the new location
 */
char *_strdup(char *buffer)
{
	int len = _strlen(buffer) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
		return (NULL);

	_memcpy(new_str, buffer, len);

	return (new_str);
}

