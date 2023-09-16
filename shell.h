#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LETTERS 1000
#define INTERACTIVE (isatty(STDIN_FILENO))
#define MAX_PATH_LENGTH 1024

char *ppath(const char *arg, const char *direc);
char *get_path(char *arg);
int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);
void prompt();
char **getinput();

#endif
