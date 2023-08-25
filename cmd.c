#include "shell.h"
/**
 */
char *_path(char *arg)
{
	struct stat pt;
	char *cp, *cp_copy = NULL;
	char *delim, *pf, *ptoken;
	int len, lusr, pfl, i;

	delim = ":";
	cp = _getenv("PATH");

	if (stat(arg, &pt) == 0)
		return (arg);
	if (cp)
	{
		cp_copy = _strdup(cp_copy, cp);
		lusr = str_len(arg);
		ptoken = _strtok(cp_copy, delim);

		while (ptoken != NULL)
		{
			len = str_len(ptoken);
			pfl = lusr + len + 2;
			pf = malloc(pfl);
			pf[0] = '\0';
			for (i = 0; i < pfl; i++)
				pf[i] = '\0';
			str_copy(pf, ptoken);
			str_cat(pf, "/");
			str_cat(pf, arg);
			str_cat(pf, "\0");
			if (stat(pf, &pt) == 0)
			{
				free(cp_copy);
				free(ptoken);
				return (pf);
			}
			free(pf);
			free(ptoken);
			ptoken = _strtok(NULL, delim);
		}
	}
	free(cp_copy);
	return (NULL);
}
