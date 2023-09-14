#include "shell.h"

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
        char *buff_cp;
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
                buff_cp = _strdup(buff);
                token = strtok(buff, delim);
                while (token)
                {
                        count++;
                        token = strtok(NULL, delim);
                }

                toks = malloc(sizeof(char *) * count);
                token = strtok(buff_cp, delim);
                for (i = 0; i < count; i++)
                {
                        toks[i] = token;
                        token = strtok(NULL, delim);
                }
                free(buff);
        }
        return (toks);
}
