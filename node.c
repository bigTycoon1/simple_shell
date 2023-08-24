#include "shell.h"
/**
 * free_linked_list - free memory allocated for each node
 * @list:list
 */
void free_linked_list(struct Node *list)
{
	struct Node *temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}
/**
 * print_linked_list - print string in linked list
 * @list:list to print
 */
void print_linked_list(struct Node *list)
{
	while (list != NULL)
	{
		write(STDOUT_FILENO, list->env_var, _strlen(list->env_var));
		write(STDOUT_FILENO, "\n", 1);
		list = list->next;
	}
}
/**
 * wspace - check for white space
 * @c: char to check
 * Return: zero on success
 */
int wspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
/**
 * remwspace - this function remove excess white space
 * @s: character to check
 */
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
