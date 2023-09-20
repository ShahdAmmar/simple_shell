#include "shell.h"

/**
 * prompt - display a prompt
 * Return: void
 */
void prompt(void)
{
	_putchar(':');
	_putchar(')');
	_putchar(' ');
}

/**
 * getinput - read input from user and tokenize it in an array
 * Return: ptr to array
 */
char **getinput()
{
	size_t n = 0;
	int count = 0, i;
	char *buff = NULL, *buff_cp, *delim = " ", *token;
	char **toks = NULL;

	ssize_t r = getline(&buff, &n, stdin);

	if (r == -1)
	{
		free(buff);
		exit(0);
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
		toks = malloc(sizeof(char *) * (count + 1));
		token = strtok(buff_cp, delim);
		for (i = 0; i < count; i++)
		{
			toks[i] = token;
			token = strtok(NULL, delim);
		}
		toks[i] = NULL;
	

	}
	free(buff);
	return (toks);
}
