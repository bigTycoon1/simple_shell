#include "shell.h"
/**
 *  * wspace - check for white space
 *   * @c: char to check
 *    * Return: zero on success
 *     */
int wspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
/**
 *  * remwspace - this function remove excess white space
 *   * @s: character to check
 *    */
void remwspace(char *s)
{
	int len = strlen(s);
	int i = 0, j = len - 1, k;
	int last, c, m;

	if (s == NULL)
		return;
	while (i < len && wspace(s[i]))
		i++;
	while (j >= i && wspace(s[j]))
		j--;
	k = 0;
	while (i <= j)
		s[k++] = s[i++];
	s[k] = '\0';
	last = 0;
	c = 0;
	for (m = 0; m <= j; m++)
	{
		if (s[m] != ' ')
		{
			s[last++] = s[m];
			c = 0;
		}
		else if (c == 0)
		{
			s[last++] = s[m];
			c++;
		}
	}
	s[last] = '\0';
}
