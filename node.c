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
	int i = 0, k = 0;
	int last = -1;

	if (s == NULL)
		return;
	while (i < len)
	{
		if (!wspace(s[i]))
		{
			last = i;
			s[k++] = s[i++];
		}
		else
			i++;
	}
	if (last >= 0)
		s[last + 1] = '\0';
	else
		s[0] = '\0';
}
