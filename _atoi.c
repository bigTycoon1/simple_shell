#include "shell.h"

/**
 * interactive - interactive mode
 * @info: info to the address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if char is delimeter
 * @c: the char to check
 * @delim: delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks if its alphabetic character
 * @c: the chara to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - convert a string representing an integer
 *@s: the string to be converted
 *Return: 0 if no num in string, converted num otherwise
 */

int _atoi(char *s)
{
	int x, stats = 1, slt = 0, output;
	unsigned int result = 0;

	for (x = 0;  s[x] != '\0' && slt != 2; x++)
	{
		if (s[x] == '-')
			stats *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			slt = 1;
			result *= 10;
			result += (s[x] - '0');
		}
		else if (slt == 1)
			slt = 2;
	}

	if (stats == -1)
		output = -result;
	else
		output = result;

	return (output);
}
