#include "shell.h"
/**
 * _getline - this function read input from user
 * Return:input parse
 */
char *_getline(void)
{
	ssize_t nread;
	char c = 0;
	int i = 0;
	char *lineptr = malloc(sizeof(char) * BUFFER);

	if (lineptr == NULL)
		return (NULL);

	while (c != EOF && c != '\n')
	{
		nread = read(STDIN_FILENO, &c, 1);
		if (nread == 0 || nread == -1)
		{
			free(lineptr);
			if (nread == 0)
			{
				free(lineptr);
				return (NULL);
			}
			if (nread == -1)
			{
				perror("Error: ");
				free(lineptr);
			}
			return (NULL);
		}
		lineptr[i] = c;
		if (i + 1 >= BUFFER)
		{
			lineptr = _realloc(lineptr, i + 1);
			if (lineptr == NULL)
			{
				free(lineptr);
				return (NULL);
			}
		}
		i++;
	}
	lineptr[i] = '\0';
	remwspace(lineptr);
	hash(lineptr);
	return (lineptr);
}
