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


#endif
