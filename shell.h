#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stddef.h>
#include <stdbool.h>

#define BUFFER 5024
#define MAX_ARGS 1024
#define UNUSED  __attribute__((unused))

extern char **environ;
int ex_code;
static char *cmd UNUSED;

/**
 * struct Node - node structure
 * @env_var: environment variable
 * @next: next node
 */
struct Node
{
	char *env_var;
	struct Node *next;
};
static struct Node *newNode(char *env_var) UNUSED;
/**
 * newNode - Creates a new node for a linked list
 * @data: Data value to be stored in the new node
 * Return: Pointer to the newly created node
 */
static struct Node *newNode(char *env_var)
{
	struct Node *node = malloc(sizeof(struct Node));
	
	if (node == NULL)
		return NULL;
	node->env_var = env_var;
	node->next = NULL;
	return node;
}
static void addNode(struct Node **head, struct Node *node) UNUSED;
/**
 * addNode - Adds a node to the end of a linked list
 * @head: Pointer to the head of the linked list
 * @node: Node to be added to the linked list
 */
static void addNode(struct Node **head, struct Node *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		struct Node *current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}
void free_linked_list(struct Node *list);

int _env(void);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);
void print_linked_list(struct Node *list);
void add_env_var(struct Node **list, const char *name, const char *value);
void update_environ(struct Node *list);

/* STD HELPER FUNCTION */
int _putchar(char c);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_strdup(const char *src);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _atoi(const char *s);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(const char *s, char *c);
const char *_strchr(const char *s, char c);

/* PROTOTYPES */
ssize_t _getline(char **lineptr, size_t *n);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *name);
char *_get_command_name(const char *path);
char *which(char *command);
void _exec(char **arg, char *av, int count);
void _execve(char *c, char **a, char **e);
void _perror(char *err, int count, char *c);
void _print(char *s);
void print_number(int n);
char *read_input(void);
void remove_trailing_and_leading_spaces(char *str);
void tokenize(char *command, char *argv[MAX_ARGS]);
int num_args(char *argv[]);
int _1exit(char *status, int c, char *a, char **ag);
int process_command(char **argv);
int access_check(char **arg, char *cmd, char *err, int c, char **e);
void _perrore(char *err, int count, char *c, char *arg);
void handle_sigint(int signo __attribute__((unused)));
void remwspace(char *s);
bool wspace(char s);
void cd(char *path);
void handle_segfault(int signo __attribute__((unused)));


#endif
