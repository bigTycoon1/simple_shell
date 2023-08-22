#include "shell.h"
/**
 */
void handle_sigint(int signo __attribute__((unused)))
{
	write(1, "\n", 1);
	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
	exit(0);
}
/**
 * read_input - Read user input from stdin
 * Return:Pointer to the input command string
 */
char *read_input(void)
{
	char *cmd1 = NULL;
	size_t n = 0;

	ssize_t bytes_read = _getline(&cmd1, &n);

	if (bytes_read <= 0)
	{
		free(cmd1);
		return NULL;
	}

	signal(SIGINT, handle_sigint);
	return (cmd1);
}
/**
 */
void handle_segfault(int signo __attribute__((unused)))
{
	exit(1);
}
/**
 */
int access_check(char **arg, char *cmd, char *err, int c, char **e)
{
	pid_t checkid;
	char *p = NULL;

	p = (cmd == NULL) ? arg[0] : cmd;
	if (access(p, X_OK) == 0)
	{
		checkid = fork();
		if (checkid == 0)
		{
			_execve(p, arg, e);
		}
		return (0);
	}
	else
	{
		_perror(err, c, p);
		return (1);
	}
}
