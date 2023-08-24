#include "shell.h"
/**
 * _getline - replicate std getline function
 * Return:input
 */
char *_getline(void)
{
	static char b[MAX_ARGS];
	static size_t len;
	static size_t pos;

	char *l = NULL;
	size_t llen = 0;
	size_t lindex = 0;
	size_t cl, i;

	while (1)
	{
		if (pos >= len)
		{
			len = read(0, b, MAX_ARGS);
			if (len == 0)
				break;
			if (len == (size_t)-1)
				return (NULL);
			pos = 0;
		}
		lindex = pos;
		while (lindex < len && b[lindex] != '\n')
			lindex++;
		cl = lindex - pos;
		l = realloc(l, (llen + cl + 1) * sizeof(char));
		if (l == NULL)
			return (NULL);
		for (i = 0; i < cl; i++)
			l[llen + i] = b[pos + i];
		llen += cl;
		pos = lindex + 1;
		if (lindex < len && b[lindex] == '\n')
		{
			l[llen] = '\0';
			return (l);
		}
	}
	return (l);
}
