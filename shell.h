#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>

#define BUFFER 1024
#define UNUSED  __attribute__((unused))

extern char **environ;
/**
 */
typedef struct Node
{
	char **env_var;
	int data;
} Node;
/**
 */
typedef struct alias_s
{
	char *name;
	char *v;
	struct alias_s *next;
} alias_t;

/** HELPER FUNCTIONS **/
int str_len(char *s);
void str_copy(char *src, char *dest);
void str_cat(char *src, char *dest);
char *_strchr(char *s, char c);
int _strcspn(char *s, char *src);
int _strcmp(char *s, char *c);
char *_strdup(char *dup, char *str);
int _atoi(char *s);
void *_realloc(void *ptr, size_t size);
char *_memcpy(char *dest, char *src, unsigned int n);
void hash(char *b);
int wspace(char s);
void remwspace(char *s);


/** PROTOTYPE **/
char *_getenv(const char *name);
int _env(Node *e);
void _env_help(char *input, Node *e);
int _setenv(char **arg);
int _unsetenv(char **arg);
void _1exit(char **r, int status);
void free_arr(char **arg);
int _perror(char *s);
void print_error(char **a, char *err);
char *_strtok(char *str, const char *delim);
int env_cmd(char **arg);
int exec(char **arg);
char *_path(char *arg);
char *_getline(void);
char *prompt(ssize_t *arg);
char **tokenize(char *input , char **arg, ssize_t len);
void p_alias( alias_t *a);
void s_alias(alias_t **a, char *name, char *v);
void init_a(alias_t **a);
int a_cmd(char *arg[BUFFER], int num_arg);
void print_aliases(alias_t *a);
#endif
