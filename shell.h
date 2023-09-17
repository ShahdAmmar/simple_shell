#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LETTERS 1024
#define INTERACTIVE (isatty(STDIN_FILENO))
#define MAX_PATH_LENGTH 1024

extern char **environ;

int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);

void prompt(void);
char **getinput();

char *ppath(const char *arg, const char *direc);
char *get_path(char *arg);

int check_builtIn(char *arg);

#endif
