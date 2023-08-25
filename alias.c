#include "shell.h"
/**
 * p_alias - this print alias
 * @alias: print the alias
 */
void p_alias(alias_b *alias)
{
	if (alias->v[0] != '\'')
	{
		write(1, "alias ", 6);
		write(1, alias->n, _strlen(alias->n));
		write(1, "='", 2);
		write(1, alias->v, _strlen(alias->v));
		write(1, "'\n", 2);
	}
	else
	{
		write(1, "alias ", 6);
		write(1, alias->n, _strlen(alias->n));
		write(1, "=", 1);
		write(1, alias->v, _strlen(alias->v));
		write(1, "\n", 1);
	}
}
/**
 * s_alias - this function set alias
 * @aliases: alias head
 * @n:name
 * @v: value
 */
void s_alias(alias_b **aliases, char *n, char *v)
{
	alias_b *alias;

	for (alias = *aliases; alias; alias = alias->next)
		if (_strcmp(alias->n, n) == 0)
			break;
	if (alias)
	{
		free(alias->v);
		alias->v = _strdup(v);
	}
	else
	{
		alias = malloc(sizeof(*alias));
		if (!alias)
			return;
		alias->n = _strdup(n);
		alias->v = _strdup(v);
		alias->next = *aliases;
		*aliases = alias;
	}
	free(alias);
}
/**
 * init_a - initialise alias
 * @aliases:head
 */
void init_a(alias_b **aliases)
{
	s_alias(aliases, "l", "ls -CF");
	s_alias(aliases, "la", "ls -A");
	s_alias(aliases, "ll", "ls -alF");
	s_alias(aliases, "ls", "ls --color=auto");
}
/**
 * a_cmd - set alias cmd
 * @arg:argument
 * @UNUSED: unused var
 * Return: 0
 */
int a_cmd(char *arg[MAX_ARGS], int num_arg UNUSED)
{
	static alias_b *aliases;
	static int i;
	int j;
	char *n, *v;
	alias_b *alias;

	if (!i)
	{
		init_a(&aliases);
		i = 1;
	}
	if (_strcmp(arg[0], "alias") != 0)
		return (0);
	if (num_arg == 1)
	{
		for (alias = aliases; alias; alias = alias->next)
			p_alias(alias);
		return (1);
	}
	for (j = 1; j < num_arg; j++)
	{
		n = arg[j];
		v = _strchr(arg[j], '=');
		if (v)
		{
			*v = '\0';
			v++;
			if (*v == '\0')
				continue;
			s_alias(&aliases, n, v);
		}
		else
			print_aliases(aliases);
	}
	return (1);
}
