#include "shell.h"
/**
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			perror("malloc");
			return (-1);
		}
	}
	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (i >= *n -1)
		{
			*n *= 2;
			char *new_lineptr = (char *)realloc(*lineptr, *n);
			if (new_lineptr == NULL)
			{
				perror("realloc");
				free(*lineptr);
				return (-1);
			}
			*lineptr = new_lineptr;
		}
		(*lineptr)[i++] = c;
	}
	if (c == EOF && i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
