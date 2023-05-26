#include "shell.h"
/**
 * prompt - display prompt
 */
void prompt(void)
{
	printf("$ ");
}
/**
 * read_input - This function read input from stdin
 * Return: input
 */
char *read_input()
{
	char *input = NULL;
	size_t bufsize = 0;

	_getline(&input, &bufsize, stdin);

	return (input);
}
/**
 * _execve - This function print env process
 * @command: input from stdin
 */
void _execve(char *command)
{
	int stat;
	pid_t pid = fork();

	if (pid < 0)
		perror("./shell");
	else if (pid == 0)
	{
		char *args[] = {"/bin/ls", NULL};

		args[1] = command;
		execvp(args[0], args);

		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &stat, 0);
}
/**
 * main - Entry point
 * Return: Always zero
 */
int main(void)
{
	char *command;

	while (1)
	{
		prompt();

		command = read_input();

		if (command == NULL)
		{
			printf("\n");
			break;
		}
		command[my_strcspn(command, "\n")] = '\0';
		_execve(command);
		free(command);
	}
	return (0);
}
