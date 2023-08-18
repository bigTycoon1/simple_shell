#include "shell.h"
/**
  *_strlen - function that returns the length of a string
  *@s: string to be return
  *
  *Return: lenght of the string
  */
int _strlen(char *s)
{
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		count++;
	}
	return (count);
}

/**
 * *_strcpy - function that copies the string pointed
 * @dest: data type string
 * @src: data type string
 *
 *Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  *_memcpy -  function that copies memory area
  *@dest: destination to be copied to
  *@src: memory area where n bytes is copied
  *@n: part of bytes in memory area src
  *
  *Return: pointer to dest
  */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
