#include "main.h"
/**
 */
int main()
{
	char *line;
	char *command;
	char *args[BUFFER];
	int i = 0;


	while ((line = _getline()) != NULL)
	{
		if (_strcmp(line, "exit") == 0)
			exit(0);
		else if (_strcmp(line, "env") == 0)
			print_env();
		else
		{
			command = strtok(line, " ");
			while (command != NULL)
			{
				args[i++] = command;
				command = strtok(NULL, " ");
			}
			args[i] = NULL;
			execute_command(args[0], args);
		}
	}
	return (0);
}
