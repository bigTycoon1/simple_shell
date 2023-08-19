#include "shell.c"
/**
 * _strtok - replicate the std lib strtok
 * @str:string
 * @delim:delimiter
 * Return:token start
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken = NULL;
	char *tokenStart, *tokenEnd;

	if (str != NULL)
		lastToken = str;
	else if (lastToken == NULL)
		return (NULL);
	tokenStart = lastToken;
	while (*tokenStart && strchr(delim, *tokenStart))
		tokenStart++;

	if (*tokenStart == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}
	tokenEnd = tokenStart + 1;
	while (*tokenEnd && !strchr(delim, *tokenEnd))
		tokenEnd++;
	if (*tokenEnd == '\0')
		lastToken = NULL;
	else 
	{
		*tokenEnd = '\0';
		lastToken = tokenEnd + 1;
	}
	return (tokenStart);
}