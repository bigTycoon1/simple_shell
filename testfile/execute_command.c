#include "main.h"
/**
 */
void execute_command(char *command, char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execvp(command, args);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("Error forking");
	else
		wait(NULL);
}
