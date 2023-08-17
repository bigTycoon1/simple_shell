#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER 5024

int _putchar(char c);
int _strcmp(char *s, char *c);
char *_strchr(char *s, char c);
ssize_t _getline(char **lineptr, size_t *n);
char *_strtok(char *str, const char *delim);


#endif
