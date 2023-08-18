#include "shell.h"
/**
  * _strcat - function that concatenates two strings
  * @dest: destinatin string
  * @src: source string
  *
  * Return: dest
  */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; src[j] != '\0'; ++j, ++i)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}

/**
  *_atoi - function that convert a string to an integer.
  *@s: string to be converted
  *
  *Return: integer
  */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}

/**
  * _strncpy -  function that copies a string
  * if (n > src), it will pad n - src of 0's to the dest,
  * @dest: the destination string
  * @src: the string to be copied
  * @n: number of text to be copied
  *
  *Return: dest
  */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (*src && n)
	{
		*(dest + i++) = *src++;
		--n;
	}
	while (n--)
	{
		*(dest + i++) = '\0';
	}
	return (dest);
}

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
	{
		;
	}

	if (s[i] == c)
	{
		return (s + i);
	}
	else
	{
		return (NULL);
	}
}
