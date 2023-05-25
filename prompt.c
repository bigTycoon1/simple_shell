#include "shell.h"
/**
 * main - This program that prints "$ ", wait for the user to enter a command,
 * prints it on the next line.
 *
 * Return: Always zero.
 */
int main(void)
{
	char array[100];

	printf("$ ");
	fgets(array, sizeof(array), stdin);
	printf("%s\n", array);

	return (0);
}
