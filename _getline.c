#include "shell.h"
/**
 * wspace - check for white space
 * @c: char to check
 * Return: zero on success
 */
int wspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
/**
 * remwspace - this function remove excess white space
 * @s: character to check
 */
void remwspace(char *s)
{
	int len = strlen(s);
	int i = 0, k, j = len - 1;
	int d, c = 0, last = 0;

	if (s == NULL)
		return;
	while (i < len && wspace(s[i]))
		i++;
	while (j >= i && wspace(s[j]))
		j--;
	k = 0;
	while (i <= j)
		s[k++] = s[i++];
	s[k] = '\0';
	for (d = 0; d <= j; d++)
	{
		if (s[d] != ' ')
		{
			s[last++] = s[d];
			c++;
		}
	}
	s[last] = '\0';
}

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
				exit(ex_code);
			if (nread == -1)
				perror("Error: ");
		}
		lineptr[i] = c;
		if (lineptr[0] == '\n')
		{
			free(lineptr);
			return ("\0");
		}
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
		lineptr[i - 1] = '\0';
		remwspace(lineptr);
		hash(lineptr);
		return (lineptr);
}
