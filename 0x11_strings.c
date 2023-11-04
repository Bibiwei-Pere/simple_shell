#include "0x1_main.h"

/**
 * _strlen -
 * @buffer:
 * Return:
*/
int _strlen(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		;

	return (i);
}


/**
 * _strncmp -
 * @destination:
 * @source:
 * @num:
 * Return:
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
 * _strcpy -
 * @destination:
 * @source:
 * Return:
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
 * _strcat -
 * @destination:
 * @source:
 * Return:
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

