#include "shell.h"

#define INTERACTIVE (isatty(STDIN_FILENO))

void prompt()
{
	_putchar(':');
	_putchar(')');
	_putchar(' ');
}

char **getinput()
{
        size_t n = 0;
        char *buff = NULL;
        char *delim = " ";
        int count = 0, i;
	char *token;
	char **toks = NULL;

        ssize_t r = getline(&buff, &n, stdin);
        if (r == -1)
        {
                if (INTERACTIVE)
                        _putchar('\n');
        }
        if (r > 0)
        {
                buff[r - 1] = '\0';
                r--;
        }
        if (buff)
        {
                token = strtok(buff, delim);
                while (token)
                {
                        count++;
                        token = strtok(NULL, delim);
                }

                token = strtok(buff, delim);
                for (i = 0; i < count; i++)
                {
                        toks[i] = token;
                        token = strtok(NULL, delim);
                }
                free(buff);
        }
	return (toks);
}

int main()
{
        char **array;
	pid_t pid;

        while (1)
        {
                if (INTERACTIVE)
                        prompt();
                array = getinput();

                pid = fork();
                if (pid == -1)
                {
                        perror("fork");
                        exit(EXIT_FAILURE);
                }
                else if (pid == 0)
                {
			int val = execve(array[0], array, NULL);
                        if (val == -1)
                        {
                                perror("excute");
                                exit(EXIT_FAILURE);
                        }
                }
                else
                {
                        wait(NULL);
                }
        }
        return (0);
}
