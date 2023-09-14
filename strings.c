#include "shell.h"

/**
 * _putchar - writes character c to stdout
 * @c: character to print
 * Return: 1
 */

int _putchar(char c)
{
        return (write(1, &c, 1));
}

/**
 * _puts - print string followed by new line
 * @str: string
 * Return: void
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
