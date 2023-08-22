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
/**
 * newNode - Creates a new node for a linked list
 * @env_var: value to be stored in the new node
 * Return: Pointer to the newly created node
 */
static struct Node *newNode(char *env_var)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
		return (NULL);
	node->env_var = env_var;
	node->next = NULL;
	return (node);
}
/**
 * addNode - Adds a node to the end of a linked list
 * @head: Pointer to the head of the linked list
 * @node: Node to be added to the linked list
 */
static void addNode(struct Node **head, struct Node *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		struct Node *current = *head;

		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}
