#include "shell.h"
/**
 * _getline - This is my version of the getline function
 * @lineptr: a pointer to a block allocated with malloc or calloc which
 * allocates memory for the program when run.
 * @n: the size in bytes of the block of memory pointed to by lineptr
 * @stream: stream from where to read the line
 *
 * Return: Zero on success, -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_size = 1024;
	size_t i = 0;
	int c;
	char *buffer = (char *) malloc(buffer_size);

	if (!buffer)
		return (-1);

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= buffer_size - 1)
		{
			buffer_size *= 2;
			char *new_buffer = realloc(buffer, buffer_size);

			if (!new_buffer)
			{
				free(buffer);
				return (-1);
			}
			buffer = new_buffer;
		}
		buffer[i++] = (char) c;
		if (c == '\n')
			break;
	}
	if (i == 0 && c == EOF)
	{
		free(buffer);
		return (-1);
	}
	buffer[i] = '\0';
	if (i >= *n)
	{
		*lineptr = (char *) realloc(*lineptr, i + 1);

		if (!*lineptr)
		{
			free(buffer);
			return (-1);
		}
	}
		strncpy(*lineptr, buffer, i + 1);
		*n = i + 1;
		free(buffer);
		return ((ssize_t) i);
}
/**
 * main - Entry point test file
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("Enter a line of text:\n");
	read = _getline(&line, &len, stdin);

	if (read != -1)
		printf("Line read: %s\n", line);
	else
		printf("Failed to read line.\n");
	free(line);

	return (0);
}
