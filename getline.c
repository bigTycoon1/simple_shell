#include "shell.h"
/**
 * _getline - replicate std getline function
 * Return:input
 */
char *_getline(void)
{
	int i = 0;
	ssize_t nread;
	char c = 0, *new_b;
	char *b = malloc(sizeof(char) * (BUFFER + 1));

	if (b == NULL)
		return (NULL);
	while (c != EOF && c != '\n')
	{
		nread = read(STDIN_FILENO, &c, 1);
		if (nread == 0 || nread == -1)
		{
			free(b);
			if (nread == -1)
				perror("Error ");
			return (NULL);
		}
		b[i] = c;
		if (b[0] == '\n')
		{
			free(b);
			return ("");
		}
		if (i + 1 >= BUFFER)
		{
			new_b = _realloc(b, i + 1);
			if (new_b == NULL)
			{
				free(b);
				return (NULL);
			}
			b = new_b;
		}
		i++;
	}
	b[i] = '\0';
	remwspace(b);
	hash(b);
	return (b);
}
