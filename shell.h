#ifndef _SHELL_H_
#define _SHELL_H_

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

extern char **environ;
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *my_strchr(const char *str, int ch);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
#endif /* SHELL_H */
