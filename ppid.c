#include "shell.h"
/**
 * main - PPID
 *
 * Return: Always zero.
 */
int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);

	return (0);
}
