#include "shell.h"
/**
 */
char *_getline(void)
{
	static char b[BUFFER];
	static size_t blen;
	static size_t pos;

	char *l = NULL;
	size_t llen = 0;
	size_t lindex = 0;
	size_t cl, i;

	while (1)
	{
		if (pos >= blen)
		{
			blen = read(0, b, BUFFER);
			if (blen == 0)
				break;
			if (blen == (size_t)-1)
				return (NULL);
			pos = 0;
		}
		lindex = pos;
		while (lindex < blen && b[lindex] != '\n')
			lindex++;
		cl = lindex - pos;
		l = realloc(l, (llen + cl + 1) * sizeof(char));
		if (l == NULL)
			return (NULL);
		for (i = 0; i < cl; i++)
			l[llen + i] = b[pos + i];
		llen += cl;
		pos = lindex + 1;
		if (lindex < blen && b[lindex] == '\n')
		{
			l[llen] = '\0';
			return (l);
		}
	}
	return (l);
}
