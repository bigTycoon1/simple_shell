#include "shell.h"
/**
 * _env - print env var
 * Return: 0
 */
int _env(void)
{
	char **env;
	struct Node *environ_list = NULL;

	for (env = environ; *env != NULL; env++)
		addNode(&environ_list, newNode(*env));

	print_linked_list(environ_list);
	free_linked_list(environ_list);
	return (0);
}
/**
 * _setenv - set an env var
 * @name: var name
 * @value: value to set
 * Return: 0
 */
int _setenv(const char *name, const char *value)
{
	char **env;
	struct Node *environ_list = NULL;

	for (env = environ; *env != NULL; env++)
		addNode(&environ_list, newNode(*env));

	add_env_var(&environ_list, name, value);
	update_environ(environ_list);
	free_linked_list(environ_list);

	return (0);
}
/**
 * _unsetenv - unset an env var
 * @name:var name
 * Return: -1
 */
int _unsetenv(const char *name)
{
	char **env_var;
	char **env;
	size_t name_length = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_length) == 0 &&
				(*env)[name_length] == '=')
		{
			for (env_var = env; *env_var != NULL; env_var++)
			{
				*env_var = *(env_var + 1);
			}
			return (0);
		}
	}
	return (-1);
}
