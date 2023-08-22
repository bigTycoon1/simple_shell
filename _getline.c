#include "shell.h"
#include <stdbool.h>
/**
 * wspace - check for white space
 * @c: char to check
 * Return: zero on success
 */
bool wspace(char c)
{
	return (c == ' ' || c == '\t');
}
/**
 * remwspace - this function remove excess white space
 * @s: character to check
 */
void remwspace(char *s)
{
	int len = strlen(s);
	int i = 0, j = len - 1;
	int k = 0, m;
	bool lastWasSpace = false;

	while (i < len && wspace(s[i]))
		i++;
	while (j >= i && wspace(s[j]))
		j--;

	for (m = i; m <= j; m++)
	{
		if (!wspace(s[m]))
		{
			s[k++] = s[m];
			lastWasSpace = false;
		}
		else if (!lastWasSpace)
		{
			s[k++] = ' ';
			lastWasSpace = true;
		}
	}
	s[k] = '\0';
}

/**
 * _getline - this function read input fron user
 * @lineptr:line pointer
 * @n: length
 * Return:input
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	char *newptr;
	size_t buffersize = *n;
	ssize_t nread;
	char c = 0;
	size_t i = 0;

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(buffersize);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((nread = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == '\n')
			break;
		(*lineptr)[i++] = c;

		if (i >= buffersize - 1)
		{
			buffersize *= 2;
			newptr = (char *)_realloc(*lineptr, buffersize);

			if (newptr == NULL)
				return (-1);

			*lineptr = newptr;
			*n = buffersize;
		}
	}
	if (i == 0 && nread == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	remwspace(*lineptr);
	return (i);
}
