#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER 5024
extern char **environ;
int ex_code = 0;

/**
 * struct Node - node structure
 * @env_var: environment variable
 * @next: next node
 */
struct Node
{
	char *env_var;
	struct Node *next;
}

static struct Node *create_node(const char *env_var);
static void append_node(struct Node **list, struct Node *node);
static void free_linked_list(struct Node *list);
static void print_linked_list(struct Node *list);
static void add_env_var(struct Node **list, const char *name, const char *value);
static void update_environ_array(struct Node *list);

int _putchar(char c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_strdup(const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _atoi(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s, char *c);
char *_strchr(char *s, char c);
ssize_t _getline(char **lineptr, size_t *n);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *name);
char *_get_command_name(const char *path);
char *which(char *command);
void _exec(char **_argum, char *av, int count);
void _execve(char *c, char **a, char **e);
void _perror(char *err, int count, char *c);
void _print(char *s);
void _pnumber(int n);


#endif
