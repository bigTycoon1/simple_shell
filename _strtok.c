#include "shell.h"
/**
 * _strtok - replicate the std lib strtok
 * @str:string
 * @delim:delimiter
 * Return:token start
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken;
	char *token;
	int  i = 0, size = 0;

	if (str != NULL)
		lastToken = str;
	while (lastToken[i] != '\0')
	{
		if (lastToken[i] == *delim)
		{
			lastToken[i] = '\0';
			token = lastToken;
			lastToken = &lastToken[i + 1];
			return (token);
		}
		else
			i++;
	}
	if (lastToken[0] != '\0')
	{
		while (lastToken[size] != 0)
			size++;
		token = lastToken;
		lastToken += size;
		return (token);
	}
	return (NULL);
}
