#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024

extern char **environ;

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void execute_command(char *command, char *args[]);
char *_getline();
void print_env();

#endif
