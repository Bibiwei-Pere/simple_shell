#include "0x1_main.h"

/**
 * _strtok - Custom strtok() that splits input or buffer into tokens
 *           (commands and arguments). Used in tokenize() and path_location().
 * @buffer: Input
 * @delimeters: What separates the tokens (commands from argument)
 * Return: First token (token_start or Command) if successful
 */
char *_strtok(char *buffer, const char *delimeters)
{
	static char *saved_buf;
	char *token_start, *token_end;

	/* Save the input to be parsed else return NULL if empty*/
	if (buffer != NULL)
		saved_buf = buffer;
	else if (saved_buf == NULL)
		return (NULL);

	/* Find the beginning of the token & return NULL */
	token_start = saved_buf;
	while (*token_start != '\0' && _strchr(delimeters, *token_start) != NULL)
		token_start++;
	if (*token_start == '\0')
	{
		saved_buf = NULL;
		return (NULL);
	}

	/* Find the end of token & return NULL else terminate & update saved_buf */
	token_end = token_start;
	while (*token_end != '\0' && _strchr(delimeters, *token_end) == NULL)
		token_end++;
	if (*token_end == '\0')
		saved_buf = NULL;
	else
	{
		*token_end = '\0';
		saved_buf = token_end + 1;
	}

	return (token_start);
}

/**
 * _strchr - Loop through the input until the end or
 *           the character is found. Used in _strtok()
 * @buffer: Input
 * @character: Character
 * Return: Always buffer or NULL if successful
 */
char *_strchr(const char *buffer, int character)
{
	for (; *buffer != '\0'; buffer++)
	{
		/* Return a ptr to the first occurrence of the character else NULL*/
		if (*buffer == character)
			return ((char *)buffer);
	}

	return (NULL);
}

