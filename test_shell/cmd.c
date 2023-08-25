#include <stdlib.h>
#include "shell.h"
/**
 * process_command - process shell command
 * @args:array of string
 * Return:0 if command found, 1 if not
 */
int process_command(char **args)
{
	int num_arg = count_argument(args);

	if (_strcmp(args[0], "cd") == 0)
	{
		if (num_arg >= 1)
		{
			cd(args[1]);
			return (0);
		}
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		_env();
		return (0);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		if (num_arg == 3)
		{
			_setenv(args[1], args[2]);
			return (0);
		}
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (num_arg == 2)
		{
			_unsetenv(args[1]);
			return (0);
		}
	}
	return (1);
}
/**
 * process_exit - process exit command in shell
 * @status:string status
 * @c:command count
 * @sn:shell name
 * @arg:argumenti
 * Return:exit status code
 */
int process_exit(char *status, int c, char *sn, char **arg)
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
				print_error(sn, c, arg[0], status);
				ex_code = 2;
				return (500);
			}
			j++;
		}
		i = _atoi(status);
	}
	return (i);
}
/**
 * print_error - related to numeric values
 * @err: err message
 * @count:show position
 * @cmd_name:name of command
 * @arg:argument
 */
void print_error(char *err, int count, char *cmd_name, char *arg)
{
	_print(err);
	_print(": ");
	print_number(count);
	_print(": ");
	_print(cmd_name);
	_print(": Illegal number: ");
	_print(arg);
	_print("\n");
}
