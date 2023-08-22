#include "shell.h"
/**
 * _print - print char
 * @s:char to print
 */
void _print(char *s)
{
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}
}
/**
 * print_number - print number
 * @n:number to print
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
	       n = -n;
	}

	if (n >= 10)
	{
		print_number(n / 10);
	}
	_putchar((n % 10) + '0');
}
/**
 * _perror - print errors
 * @err:error
 * @count:count command
 * @c:file name
 */
void _perror(char *err, int count, char *c)
{
	ex_code = 127;
	_print(err);
	_print(": ");
	print_number(count);
	_print(": ");
	_print(c);
	_print(": not found\n");
}
/**
 * _execve - execute err code
 * @c:command
 * @a:command args
 * @e:env var
 */
void _execve(char *c, char **a, char **e)
{
	if (execve(c, a, e) == -1)
		ex_code = 127;
	ex_code = 1;
}
