#include "0x1_main.h"

/**
 * _getline - Collect inputs from user
 * @ptbuffer: Store the address of the input collected
 * @buf_size: Size of the input
 * Return: Always 0 if successful
 */
int _getline(char **ptbuffer, size_t *buf_size)
{
	int num_char = 0;
	size_t i = 0, new_buf_size;
	char input;
	char *new_buffer;

	if (*ptbuffer == NULL || *buf_size == 0)
	{
		*buf_size = 100;
		*ptbuffer = malloc(*buf_size);
		if (*ptbuffer == NULL)
			return (-1);
	}

	while ((num_char = read(STDIN_FILENO, &input, 1)) > 0)
	{
		if (input == '\n')
			break;
		(*ptbuffer)[i++] = input;

		if (i == *buf_size)
		{
			new_buf_size = *buf_size * 2;
			new_buffer = (char *)malloc(new_buf_size);
			if (new_buffer == NULL)
				return (-1);
			_memcpy(new_buffer, *ptbuffer, *buf_size);
			free(*ptbuffer);
			*ptbuffer = new_buffer;
			*buf_size = new_buf_size;
		}
	}
	if (num_char == 0 && i == 0)
	{
		free(*ptbuffer);
		exit(EXIT_SUCCESS);
	}
	(*ptbuffer)[i] = '\0';

	return (num_char);
}

/**
 * _memcpy - Copy previously allocated memory as used in the getline()
 * @destination: New location
 * @source: Previous location
 * @num: Size of the input to be copied
 * Return: New location if successful
 */
char *_memcpy(char *destination, char *source, unsigned int num)
{
	unsigned int j = 0;

	while (j < num)
	{
		destination[j] = source[j];
		j++;
	}

	return (destination);
}

