#include "shell.h"
/**
 * create_node - create a new node
 * @env_var:environment variable
 * Return:new node
 */
static struct Node *create_node(const char *env_var)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
	{
		return (NULL);
	}
	node->env_var = strdup(env_var);
	node->next = (NULL);
	return (node);
}
/**
 * append_node - append a node to the end of linked list
 * @list:list
 * @node:node
 */
static void append_node(struct Node **list, struct Node *node)
{
	struct Node *current;

	if (*list == NULL)
	{
		*list = node;
	}
	else
	{
		current = *list;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = node;
	}
}
/**
 * free_linked_list - free memory allocated for each node
 * @list:list
 */
static void free_linked_list(struct Node *list)
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
static void print_linked_list(struct Node *list)
{
	while (list != NULL)
	{
		write(STDOUT_FILENO, list->env_var, strlen(list->env_var));
		write(STDOUT_FILENO, "\n", 1);
		list = list->next;
	}
}

