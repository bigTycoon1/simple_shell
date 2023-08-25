#include "shell.h"
/**
 * env_cmd - this function print env command
 * @arg: argument
 * Return: 0
 */
int env_cmd(char **arg)
{
	char *env;

	if (_strcmp(arg[0], "setenv") == 0)
	{
		if (arg[1] == NULL || arg[2] == NULL)
			return (-1);
		if (_setenv(arg) == -1)
			print_error(arg, "Failed to set environment variable\n");
		return (1);
	}
	else if (_strcmp(arg[0], "unsetenv") == 0)
	{
		if (arg[1] == NULL)
		{
			write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
			return (-1);
		}
		if (unsetenv(arg[1]) == -1)
		{
			write(STDERR_FILENO, "Failed to unset environment variable\n", 37);
			return (-1);
		}
		_unsetenv(arg);
		return (1);
	}
	else if (_strcmp(arg[0], "echo") == 0)
	{
		if (arg[1] == NULL)
		{
			write(STDERR_FILENO, "Usage: echo VARIABLE\n", 21);
			return (-1);
		}
		env = getenv(arg[1]);
		if (env != NULL)
		{
			write(STDOUT_FILENO, env, strlen(env));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			write(STDOUT_FILENO, "$\n", 2);
		return (1);
	}
	return (0);
}
