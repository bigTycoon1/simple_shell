#include "shell.h"
/**
 * add_env_var - Adds a new environment variable to the linked list
 * @list:list
 * @name:name of env var
 * @value:value of env var
 */
static void add_env_var(struct Node **list, const char *name,
		const char *value)
{
	size_t name_length = _strlen(name);
	size_t value_length = _strlen(value);
	char *new_env_var = malloc(name_length + value_length + 2);
	struct Node *current_node = *list;

	if (new_env_var == NULL)
	{
		return;
	}
	_strcpy(new_env_var, name);
	_strcat(new_env_var, "=");
	_strcat(new_env_var, value);

	while (current_node != NULL)
	{
		if (_strncmp(current_node->env_var, name, name_length) == 0
				&& current_node->env_var[name_length] == '=')
		{
			free(current_node->env_var);
			current_node->env_var = new_env_var;
			return;
		}
		current_node = current_node->next;
	}

	append_node(list, create_node(new_env_var));
}
/**
 * update_environ_array - update the env array with the linked list
 * @list:list
 */
static void update_environ_array(struct Node *list)
{
	size_t node_count = 0;
	struct Node *current_node = list;
	char **new_environ;
	size_t i;

	while (current_node != NULL)
	{
		node_count++;
		current_node = current_node->next;
	}

	new_environ = malloc((node_count + 1) * sizeof(char *));
	if (new_environ == NULL)
	{
		return;
	}

	current_node = list;
	for (i = 0; i < node_count; i++)
	{
		new_environ[i] = current_node->env_var;
		current_node = current_node->next;
	}
	new_environ[node_count] = NULL;
	environ = new_environ;
}
