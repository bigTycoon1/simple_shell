#include "shell.h"
/**
 * _getenv - getenv()
 * @name: string
 * Return: path
 */
char *_getenv(const char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		char *equal = strchr(environ[i], '=');

		if (equal != NULL)
		{
			*equal = '\0';
			char *env_name = environ[i];
			char *env_value = equal + 1;

			if (_strcmp(env_name, name) == 0)
			{
				return (env_value);
			}
		}
	}
	return (NULL);
}
/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	char *path = _getenv("PATH");

	if (path != NULL)
	{
		printf("PATH: %s\n", path);
	}
	else
	{
		printf("PATH variable not found.\n");
	}

	return (0);
}
