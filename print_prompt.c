#include "shell.h"
/**
 * print_prompt - a program that print prompt
 * fd_check:check file descriptor
 * Return: user input
 */
char *print_prompt(ssize_t *fd_check)
{
	char *display_prompt = "$ ";
	char *user_input = NULL;
	size_t input_size = 0;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, display_prompt, 2);
	}
	ssize_t read_size = _getline(&user_input, &input_size, stdin);
	if (read_size == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
	}
	free(user_input);
	exit(EXIT_SUCCESS);

	*fd_check = read_size;
	return (user_input);
}
