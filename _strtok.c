#include "shell.h"
/**
 * my_strchr - This search for specific char
 * @str: string
 * @ch: char to search
 * Return: NULL
 */
char *my_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}

	return (NULL);
}
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
/**
 * main - Entry point
 *
 * Return: zero on success
 */
int main(void)
{
	char str[] = "Hello. World! This is a test.";
	const char delim[] = ", .";

	char *token = _strtok(str, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = _strtok(NULL, delim);
	}
	return (0);
}
