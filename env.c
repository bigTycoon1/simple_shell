#include "shell.h"
/**
 */
char *_getenv(const char *name)
{
	int i, j, length;

	if (name == NULL)
		return (NULL);
	length = 0;
	while (name[length])
		length++;
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < length; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (j == length && environ[i][j] == '=')
			return (&environ[i][j + 1]);
	}
	return (NULL);
}
/**
 */
int _setenv(char **arg)
{
	if (arg[1] == NULL || arg[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE\n", 29);
		return (-1);
	}
	if (setenv(arg[1], arg[2], 1) == -1)
	{
		print_error(arg, "Failed to set environment variable\n");
		return (-1);
	}
	return (0);
}
/**
 */
int _unsetenv(char **arg)
{
	if (arg[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
		return (-1);
	}
	if (getenv(arg[1]) == NULL)
		return (0);
	unsetenv(arg[1]);
	return (0);
}
