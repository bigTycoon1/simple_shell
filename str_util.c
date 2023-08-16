#include <string.h>
#include "shell.h"
/**
 * my_strdup - function to duplicate str 
 * *scr - pointer to source ofthe str
 *
 * Return - newly allocated duplicae str
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
