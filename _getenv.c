#include "shell.h"
/**
 * _strcmp - This function compare two string
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 if s1 == s2, postive number in ascii if s1 > s2,
 * negative number in ascii if s2 > s1.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
		++s1, ++s2;

	return (*s1 - *s2);
}
/**
 * _getenv - getenv()
 * @name: string
 * Return: path
 */
char *_getenv(const char *name)
{
	char **environ;
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
 * my_strchr - This search for specific char
 * @str: string
 * @ch: char to search
 * Return: NULL
 */
char *my_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		str++;
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
