#ifndef _SHELL_H_
#define _SHELL_H_

/* HEADER */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* MACROS */
#define BUFF_SIZ 1024

/* ENVIRON FUNCTION PROTOTYPE */
extern char **environ;
int _env(void);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);

/* FUNCTION PROTOTYPE */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *my_strchr(const char *str, int ch);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *name);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
int _strncpy(char *dest, char *src, int size);
int _strncmp(const char *str1, const char *str2, size_t len);
int _strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(char *s);
size_t my_strcspn(const char *str, const char *chars);
void *_memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, size_t size);
#endif /* SHELL_H */
