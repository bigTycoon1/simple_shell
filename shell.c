#include "shell.h"
/**
 * main - entry point
 * Return: 0
 */
int main(int ac UNUSED, char **av UNUSED)
{
	char *input = NULL, *input_copy;
	char *argv[MAX_ARGS], *ar[MAX_ARGS];
	int command_count = 0, r;

	signal(SIGSEGV, handle_segfault);

	do {
		command_count++;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		input = read_input();

		if (input == NULL)
		{
			exit(ex_code);
		}
		if (input[0] == '\0' || _strcmp(input, "\n") == 0)
		{
			continue;
		}
		remwspace(input);
		input_copy = _strdup(input);
		tokenize(input_copy, ar);
		tokenize(input, argv);


		if (input[0] == '\0' || _strcmp(input, "\n") == 0)
		{
			free(input);
			free(input_copy);
			continue;
		}

		if (_strcmp(argv[0], "exit") == 0)
		{
			r = _1exit(ar[1], command_count, av[0], argv);
			free(input);
			free(input_copy);
			if (r == 500)
			{
				continue;
			}
			exit(r);
		}
		if (process_command(argv) == 0)
		{
		}
		else
		{
			_exec(argv, av[0], command_count);
		}
		free(input);
		free(input_copy);
	} while (1);

	return (0);
}
