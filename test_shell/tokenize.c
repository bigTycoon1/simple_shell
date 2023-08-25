#include "shell.h"
/**
 * remove_trail_n_lead_space - Remove trailing and leading spaces from a string
 * @str:the string
 */
void remove_trail_n_lead_space(char *str)
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
 * tokenize - Tokenize a command string into an array of arguments.
 * @command: command string to tokenize.
 * @arg:An array to store the tokenized arguments.
 */
void tokenize(char *command, char *arg[MAX_ARGS])
{
	char *token;
	int i = 0;

	token = _strtok(command, " ");
	while (token != NULL)
	{
		arg[i++] = token;
		token = _strtok(NULL, " ");
	}
	arg[i] = NULL;
}
/**
 * count_argument - Count the number of arguments in an array.
 * @args:array of argument
 * Return:The number of arguments in the array.
 */
int count_argument(char *args[])
{
	int i = 0;

	while (args[i] != NULL)
		i++;
	return (i);
}
