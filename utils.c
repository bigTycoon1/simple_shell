#include "shell.h"
/**
 */
void free_arr(char **arg)
{
	char **tmp = arg;

	for (; *tmp != NULL; tmp++)
	{
		free(*tmp);
		*tmp = NULL;
	}
	free(arg);
}
/**
 */
int _perror(char *s)
{
	int i;

	if (!s)
	{
		return (0);
	}
	for (i = 0; s[i]; i++)
	{
		write(2, &s[i], 1);
	}
	return (i);
}
/**
 */
void print_error(char **a, char *err)
{
	_perror(_getenv("_"));
	_perror(": 1: ");
	_perror(a[0]);
	_perror(": ");
	_perror(err);
}
/**
 *   *_memcpy -  function that copies memory area
 *     *@dest: destination to be copied to
 *       *@src: memory area where n bytes is copied
 *         *@n: part of bytes in memory area src
 *           *
 *             *Return: pointer to dest
 *               */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
