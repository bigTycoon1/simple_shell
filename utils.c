#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s: first string to compare
 * @c: second string to compare
 * Return: return 1 when strings match
 */
int _strcmp(char *s, char *c)
{
	int i;

	for (i = 0; s[i] != '\0' && c[i] != '\0'; i++)
	{
		if (s[i] != c[i])
		{
			return (s[i] - c[i]);
		}
	}
	return (s[i] - c[i]);
}
/**
 * _strchr - search a char in a string
 * @s: string to be searched
 * @c: char to be checked
 * Return: pointer to the first occurrence of `c` in `s`
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
			;

	if (s[i] == c)
	{
		return (s + i);
	}
	else
	{
		return (NULL);
	}
}

