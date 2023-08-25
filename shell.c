#include "shell.h"
/**
 * main - entry point
 * @UNUSED: unused variable
 * Return: 0 on sucess
 */
int main(int argc UNUSED, char **argv UNUSED)
{
	char *input, **arg;
	ssize_t check;
	int i, s = 0;
	Node e;

	e.env_var = environ;
	while (1 == 1)
	{
		input = NULL, check = 0;
		input = prompt(&check);
		arg = tokenize(input, arg, check);
		if (arg[0] == NULL)
			continue;
		if (_strcmp(arg[0], "env") == 0)
		{
			free(input);
			_env(&e);
			free_arr(arg);
			continue;	}
		if (_strcmp(arg[0], "exit") == 0)
		{
			free(input);
			_1exit(arg, s);
			free_arr(arg);
			continue;
		}
		i = env_cmd(arg);
		if (i != 0)
		{
			free(input);
			free_arr(arg);
			continue;
		}
		s = exec(arg);
		if (s == 1)
			print_error(arg, "not found\n");
		free(input);
		free_arr(arg);
	}
	return (0);
}
