#include "shell.h"
/**
 * handle_sigint - Signal handler for SIGINT (Ctrl+C) signal.
 * signo: The signal number (unused, as required by the function signature).
 * @UNUSED: unused parameter
 */
void handle_sigint(int signo UNUSED)
{
	write(STDOUT_FILENO, "\n", 1);
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
		return (NULL);
	}

	signal(SIGINT, handle_sigint);
	return (cmd1);
}
/**
 * handle_segfault - Signal handler for SIGSEGV (Segmentation Fault) signal.
 * signo: The signal number (unused, as required by the function signature).
 * @UNUSED: unused parameter
 */
void handle_segfault(int signo UNUSED)
{
	exit(1);
}
/**
 * access_exec - Check access permission and execute the specified command.
 * @arg:array of argument
 * @cmd:command path
 * @err:error message
 * @c:command count
 * @e:env variable
 * Return:0 on success, 1 on access failure.
 */
int access_exec(char **arg, char *cmd, char *err, int c, char **e)
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
