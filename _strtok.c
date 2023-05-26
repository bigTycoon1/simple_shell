#include "shell.h"
/**
 * _strtok - strtok implementation
 * @str: string
 * @delim: delimiter
 *
 * Return: token
 */
char *_strtok(char *str, const char *delim)
{
	static char *tokenPtr;
	char *currentToken;

	if (str != NULL)
		tokenPtr = str;

	while (*tokenPtr != '\0' && my_strchr(delim, *tokenPtr) != NULL)
		tokenPtr++;

	if (*tokenPtr == '\0')
		return (NULL);

	currentToken = tokenPtr;

	while (*tokenPtr != '\0' && my_strchr(delim, *tokenPtr) == NULL)
	{
		tokenPtr++;
	}
	if (*tokenPtr == '\0')
	{
		tokenPtr = NULL;
	}
	else
	{
		*tokenPtr = '\0';
		tokenPtr++;
	}

	return (currentToken);
}
