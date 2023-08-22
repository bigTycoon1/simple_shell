#include <string.h>
#include "shell.h"
/**
<<<<<<< HEAD
 * _strdup - function to duplicate str
 * @src: pointer to source of the str
 *
 * Return: newly allocated duplicae str
 */
void *_strdup(const char *src)
{
	int len;
	char *new_str;

	len = _strlen(src) + 1;
	new_str = (char *)malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}

	_strcpy(new_str, src);

	return (new_str);
}
/**
 * _strncmp - function to compare
 * @s1: first string
 * @s2: second string
 * @n:length
 *
 * Return: 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	if (i < n)
	{
		return (s1[i] - s2[i]);
	}

	return (0);
}
