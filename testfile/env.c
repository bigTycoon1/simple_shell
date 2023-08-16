#include "main.h"
/**
 */
void print_env()
{
	char **env = environ;

	for (; *env != NULL; env++)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
}
