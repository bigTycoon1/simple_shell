#include "shell.h"
/**
 */
char *_strdup(char *dup, char *str)
{
	int i, len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
/**
 */
int _atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
		{
			return (-1);
		}
		else if ((*s < '0' || *s > '9') && *s != '\0')
		{
			return (-1);
		}
		else if (*s >= '0' && *s <= '9')
		{
			n = (n * 10) + (*s - '0');
		}
		else if (n > 0)
		{
			break;
		}
	} while (*s++);
	return (n);
}
/**
void print_aliases(alias_t *a)
{
	alias_t *al;

	for (al = a; al; al = al->next)
		p_alias(al);
}
**/
