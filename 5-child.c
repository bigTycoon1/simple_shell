#include "shell.h"
int main(void)
{
	int numChildren = 5;
	int i;
	for (i = 0; i < numChildren; i++)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("Error in fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[] = { "ls", "-l", "/tmp", NULL };
			execve("/bin/ls", args, NULL);

			perror("Error in execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			wait(&status);


			if (WIFEXITED(status)) 
			{
				printf("Child process %d exited with status %d\n", pid,
						WEXITSTATUS(status));
			}
			else
			{
				printf("Child process %d terminated abnormally\n", pid);
			}
		}
	}
	return (0);
}
