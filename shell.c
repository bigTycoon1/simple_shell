#include "shell.h"
int main(void)
{
	char input[BUFF_SIZ];
	int stat;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[my_strcspn(input, "\n")] = '\0';

		if (_strcmp(input, "/bin/ls") != 0)
		{
			printf("./shell: No such file or directory\n");
			continue;
		}
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execl("/bin/ls", "ls", (char *) NULL) == -1)
			{
				perror("execl");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(pid, &stat, 0);
			}

		}
	}
	return (0);
}
