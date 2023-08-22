#include "shell.h"
/**
 * _exec - execute cmmand
 * @arg:arguments
 * @av:name
 * @count:count
 */
void _exec(char **arg, char *av, int count)
{
	char *cmd1;
	char err[50];
	int status;

	_strcpy(err, av);
	ex_code = 0;

	if (arg[0][0] == '/')
	{
		if (access_check(arg, NULL, err, count, environ))
			return;
	}
	else
	{
		if (arg[0][0] != '.')
		{
			cmd1 = which(arg[0]);
			if (cmd1 == NULL)
			{
				_perror(err, count, arg[0]);
				return;
			}
			if (access_check(arg, cmd1, err, count, environ))
			{
				free(cmd1);
				return;
			}
			free(cmd1);
		}
		else
		{
			cmd1 = arg[0];
			if (access_check(arg, cmd1, err, count, environ))
				return;
		}
	}
	wait(&status);
	if (WIFEXITED(status))
		ex_code = WEXITSTATUS(status);
}
