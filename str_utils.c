#include "shell.h"
/**
 */
int str_len(char *s)
{
	int i, len = 0;

	for (i = 0; s[i] != '\0'; i++)
		len++;
	return (len);
}
/**
 */
void str_copy(char *src, char *dest)
{
	int i; 

	for (i = 0; dest[i] != '\0'; i++)
		src[i] = dest[i];
	src[i] = '\0';
}
/**
 */
void str_cat(char *src, char *dest)
{
	int i = 0, len;

	while (src[i] != '\0')
		i++;
	for (len = 0; dest[len] != '\0'; len++)
		src[i++] = dest[len];
	src[i] = '\0';
}
/**
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
/**
 */
int _strcspn(char *s, char *src)
{
	int i, j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (_strchr(src, s[i]) != NULL)
			break;
		j++;
	}
	return (j);
}
