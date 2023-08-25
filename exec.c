#include "shell.h"
/**
 */
int exec(char **arg)
{
	char *fc, *fl;
	pid_t ch;
	int i = 0;

	fc = NULL;
	fl = NULL;
	ch = -1;
	fc = arg[0];
	fl = _path(fc);

	if (fl == NULL)
		return (1);
	if (arg && access(fl, X_OK) != -1)
	{
		ch = fork();

		if (ch == -1)
		{
			print_error(arg, "command not found\n");
		}
		else if (ch == 0)
		{
			if (execve(fl, arg, NULL) == -1)
				print_error(arg, "command not found\n");
		}
		else
		{
			if (waitpid(ch, &i, 0) == -1)
				print_error(arg, "command not found\n");
		}
		if (_strcmp(fl, fc) != 0)
			free(fl);
		if (WIFEXITED(i))
			i = WEXITSTATUS(i);
		return (i);
	}
	free(fl);
	return (1);
}
