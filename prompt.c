 #include "shell.h"
/**
 */
char *prompt(ssize_t *arg)
{
	char *dp = "$ ";
	char *input = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, dp, 2);
	input = _getline();
	if (input == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	*arg = str_len(input);
	if (*arg == -1 && isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
		free(input);
		exit(EXIT_SUCCESS);
	}
	else if (*arg == -1)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	if (*arg == 0 && isatty(STDIN_FILENO))
	{
		free(input);
		return (prompt(arg));
	}
	input[_strcspn(input, "\n")] = '\0';
	return (input);
}
