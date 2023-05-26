#include "shell.h"
/**
 * _getenv - getenv()
 * @name: string
 * Return: path
 */
char *_getenv(const char *name)
{
	int i;
	char *env_name;

	for (i = 0; environ[i] != NULL; i++)
	{
		char *equal = my_strchr(environ[i], '=');

		if (equal != NULL)
		{
			*equal = '\0';
			env_name = environ[i];
			char *env_value = equal + 1;

			if (_strcmp(env_name, name) == 0)
			{
				return (env_value);
			}
		}
	}
	return (NULL);
}
