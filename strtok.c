#include "shell.h"
/**
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken;
	char *token;
	int i, j, size;

	if (str == NULL)
		str = lastToken;
	if (str == NULL)
		return (NULL);
	size = 0;
	while (str[size])
		size++;
	token = malloc(sizeof(char) * (size + 1));
	if (token == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				token[i] = '\0';
				lastToken = &str[i + 1];
				return (token);
			}
		}
		token[i] = str[i];
	}
	token[i] = '\0';
	lastToken = NULL;
	return (token);
}
