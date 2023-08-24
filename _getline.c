#include "shell.h"
/**
 * _getline - replicate std getline function
 * Return:input
 */
char *_getline(void)
{
	int i = 0;
	ssize_t nread;
	char c = 0;
	char *b = malloc(sizeof(char) * BUFFER);

	if (b == NULL)
		return (NULL);
	while (c != EOF && c != '\n')
	{
		nread = read(STDIN_FILENO, &c, 1);
		if (nread == 0 || nread == -1)
		{
			free(b);
			if (nread == 0)
				exit(ex_code);
			if (nread == -1)
				perror("Error ");
		}
		b[i] = c;
		if (b[0] == '\n')
		{
			free(b);
			return ("\0");
		}
		if (i + 1 >= BUFFER)
		{
			b = realloc(b, i + 1);
			if (b == NULL)
			{
				free(b);
				return (NULL);
			}
		}
		i++;
	}
	b[i + 1] = '\0';
	remwspace(b);
	hash(b);
	return (b);
}
