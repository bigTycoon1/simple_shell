#include <stdlib.h>
#include "shell.h"
/**
 * process_command - 
 */
int process_command(char **argv)
{
	int num_arg = num_args(argv);

	if (_strcmp(argv[0], "cd") == 0)
	{
		if (num_arg >= 1)
		{
			cd(argv[1]);
			return (0);
		}
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		return (0);
	}
	else if (_strcmp(argv[0], "setenv") == 0)
	{
		if (num_arg == 3)
		{
			_setenv(argv[1], argv[2]);
			return (0);
		}
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (num_arg == 2)
		{
			_unsetenv(argv[1]);
			return (0);
		}
	}
	return (1);
}
/**
 */
int _1exit(char *status, int c, char *a, char **ag)
{
	int i = ex_code;
	int j;

	if (status != NULL)
	{
		j = 0;
		while (status[j])
		{
			if (!(status[j] >= '0' && status[j] <= '9'))
			{
				_perrore(a, c, ag[0], status);
				ex_code = 2;
				return 500;
			}
			j++;
		}
		i = _atoi(status);
	}
	return (i);
}
/**
 */
void _perrore(char *err, int count, char *c, char *arg)
{
	_print(err);
	_print(": ");
	print_number(count);
	_print(": ");
	_print(c);
	_print(": Illegal number: ");
	_print(arg);
	_print("\n");
}
