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

int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);
void prompt();
char **getinput();

#endif
