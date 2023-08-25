#include "shell.h"
/**
 */
void _1exit(char **r, int status)
{
	char **cmd = NULL;
	int i = 0, arg;
	const char *err = "$: too many arguments\n";

	while (r[i] != NULL)
		i++;
	{
		if (i == 1)
		{
			free_arr(r);
			free(cmd);
			exit(status);
		}
		else if (i == 2)
		{
			arg = _atoi(r[1]);
			if (arg < 0)
			{
				print_error( r, "Illegal number: ");
				_perror(r[1]);
				_perror("\n");
			}
			else
			{
				free_arr(r);
				free(cmd);
				exit(arg);
			}
		}
		else
			write(STDERR_FILENO, err, strlen(err));
	}
}
