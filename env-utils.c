#include "shell.h"
/**
 * add_env_var - Add a new environment variable to the linked list.
 * @head: A pointer to the head of the linked list.
 * @name: The name of the environment variable.
 * @value: The value of the environment variable.
 */
void add_env_var(struct Node **head, const char *name, const char *value)
{
	size_t name_l = _strlen(name);
	size_t value_len = _strlen(value);
	char *new_env_var = malloc(name_l + value_len + 2);
	struct Node *current = *head;

	if (new_env_var == NULL)
	{
		return;
	}

	_memcpy(new_env_var, (void *)name, name_l);
	new_env_var[name_l] = '=';
	_memcpy(new_env_var + name_l + 1, (void *)value, value_len);
	new_env_var[name_l + value_len + 1] = '\0';

	while (current != NULL)
	{
		if (_strncmp(current->str, name, name_l) == 0 && current->str[name_l] == '=')
		{
			free(current->str);
			current->str = new_env_var;
			return;
		}
		current = current->next;
	}

	add_node(head, new_node(new_env_var));
}

/**
 * update_environ - Update the environ variable with the linked list contents.
 * @head: The head of the linked list.
 */
void update_environ(struct Node *head)
{
	size_t count = 0;
	size_t i;
	struct Node *current = head;
	char **new_environ;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	new_environ = malloc((count + 1) * sizeof(char *));
	if (new_environ == NULL)
	{
		return;
	}

	current = head;
	for (i = 0; i < count; i++)
	{
		new_environ[i] = current->str;
		current = current->next;
	}
	new_environ[count] = NULL;

	environ = new_environ;
}
/**
 * _env - Print the environment variables.
 *
 * Return: Always 0.
 */
int _env(void)
{
	char **env;
	struct Node *head = NULL;

	for (env = environ; *env != NULL; env++)
	{
		add_node(&head, new_node(*env));
	}

	print_list(head);

	free_list(head);
	return (0);
}

/**
 * _setenv - Set an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to be set.
 *
 * Return: Always 0.
 */
int _setenv(const char *name, const char *value)
{
	char **env;
	struct Node *head = NULL;
	/*extern char **environ;*/

	for (env = environ; *env != NULL; env++)
	{
		add_node(&head, new_node(*env));
	}

	add_env_var(&head, name, value);

	update_environ(head);

	free_list(head);
	return (0);
}

/**
 * _unsetenv - Delete an environment variable.
 * @name: The name of the environment variable to be deleted.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
	char **e;
	char **env;
	size_t len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			for (e = env; *e != NULL; e++)
			{
				*e = *(e + 1);
			}
			return (0);
		}
	}

	return (-1);
}
