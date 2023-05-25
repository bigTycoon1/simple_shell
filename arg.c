#include "shell.h"
/**
 * main - This program all the arguments, without using ac
 * @argc: argument countll the arguments, without using ac
 * @argv: argument vector
 *
 * Return: Alway 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char **arg = argv;

	while (*arg != NULL)
	{
		printf("%s\n", *arg);
		arg++;
	}
	return (0);
}
