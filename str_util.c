#include <string.h>
#include "shell.h"
/**
 * my_strdup - function to duplicate str 
 * *scr: pointer to source ofthe str
 *
 * Return: newly allocated duplicae str
 */
void *my_strdup(const char *src)
{
	int len;
	char *new_str;


	len = strlen(src) + 1;
	*new_str = (char *)malloc(length);

	if (new_str == NULL)
	{
		return (NULL);
	}

	strcpy(new_str, src);

	return (new_str);
}

#include <string.h>
#include "shell.h"
/**
 * my_strncmp - function to compare
 * @s1: first string
 * @s2: second string 
 *
 * Return: 0
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	char s1, s2;
	int n, i = 0;
	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
	if (s1[i] == '\0')
	{
		break;
	}
	
	}
	return 0;
}
