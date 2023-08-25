#include "shell.h"
/**
 */
char **tokenize(char *input, char **arg, ssize_t len)
{
	char *input_copy, *ptoken;
	const char *delim;
	int count = 0, n = 0, tlen;

	delim = "\n";

	input_copy = malloc(sizeof(char) * (len + 2));
	if (input_copy == NULL)
	{
		perror("Error: cannot allocate memory");
		return(NULL);
	}
	str_copy(input_copy, input);
	ptoken = _strtok(input, delim);
	while (ptoken != NULL)
	{
		count++;
		free(ptoken);
		ptoken = _strtok(NULL, delim);
	}
	count++;
	arg = malloc(sizeof(char *) * count);
	ptoken = _strtok(input_copy, delim);
	for (n = 0; ptoken != NULL; n++)
	{
		tlen = str_len(ptoken);
		arg[n] = malloc(sizeof(char) * tlen + 1);
		arg[n][tlen] = '\0';
		str_copy(arg[n], ptoken);
		free(ptoken);
		ptoken = _strtok(NULL, delim);
	}
	arg[n] = NULL;
	free(input_copy);
	return (arg);
}
