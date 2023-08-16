#include "main.h"
/**
 */
char *_getline()
{
	static char buffer[BUFFER];
	ssize_t n;

	write(STDOUT_FILENO, "$ ", 2);
	n = read(STDIN_FILENO, buffer, BUFFER);
	if (n > 0)
	{
		buffer[n - 1] = '\0';
		return (buffer);
	}
	else
		return (NULL);
}
