#include "shell.h"
/**
 * _getenv - retrieving the value of an environment variable
 * @name: argument name
 * Return: NULL
 */
char *_getenv(const char *name)
{
	char **env;
	size_t namelen = _strlen(name);

	for (env = environ; *env; env++)
	{
		if (_strncmp(*env, name, namelen) == 0 && (*env)[namelen]
				== '=')
			return (*env + namelen + 1);
	}
	return (NULL);
}

/**
 * _get_command_name - extract the name of the command from its full path.
 * @path:path to find
 * Return:pointer to path
 */
char *_get_command_name(const char *path)
{
	const char *lastslash = NULL;

	while (*path != '\0')
	{
		if (*path == '/')
			lastslash = path;
		path++;
	}
	if (lastslash != NULL)
	{
		return ((char *)(lastslash + 1));
	}
	return ((char *)path);
}

/**
 * which - searches for the location of a given command in the directories
 * listed in the PATH environment variable.
 * @command: the command
 * Return:NULL
 */
char *which(char *command)
{
	char *path_copy;
	char *dir;
	char *path = _getenv("PATH");

	if (path == NULL)
		return (NULL);

	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (NULL);

	dir = _strtok(path_copy, ":");
	while (dir != NULL)
	{
		char full_path[1024];

		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (_strdup(full_path));
		}
		dir = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
