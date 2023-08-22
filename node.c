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
		free(temp->env_var);
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
		write(STDOUT_FILENO, list->env_var, strlen(list->env_var));
		write(STDOUT_FILENO, "\n", 1);
		list = list->next;
	}
}
