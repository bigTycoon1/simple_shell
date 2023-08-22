#include "shell.h"
/**
 */
void remove_trailing_and_leading_spaces(char *str)
{
	size_t len = _strlen(str);
	size_t start = 0;
	size_t i;

	if (len > 0)
	{
		while (len > 0 && str[len - 1] == ' ')
			len--;
		str[len] = '\0';
	}

	while (str[start] == ' ')
		start++;

	if (start > 0)
	{
		i = 0;
		while (str[start + i] != '\0')
		{
			str[i] = str[start + i];
			i++;
		}
		str[i] = '\0';
	}
}
/**
 */
void tokenize(char *command, char *argv[MAX_ARGS])
{
	char *token;
	int i = 0;

	token = _strtok(command, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = _strtok(NULL, " ");
	}
	argv[i] = NULL;
}
/**
 */
int num_args(char *argv[])
{
	int i = 0;

	while (argv[i] != NULL)
		i++;
	return (i);
}
