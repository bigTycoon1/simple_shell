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
 * _realloc - replicate std realloc
 * @ptr:pointer
 * @size:new size to allocate
 * Return:new allocation pointer
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(size));

	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
/**
 * hash - check # character input
 * @b:buffer
 */
void hash(char *b)
{
	int i = 0;

	while (b[i] != '\0')
	{
		if (b[i] == '#')
			b[i] = '\0';
		i++;
	}
}

/**
void print_aliases(alias_t *a)
{
	alias_t *al;

	for (al = a; al; al = al->next)
		p_alias(al);
}
**/
