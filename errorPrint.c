#include "shell.h"

/**
 * _errorputs - puts without newline
 * @str: string
 * Return: void
 */

void _errorputs(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
 * _printe - print error messgae
 * @filename: argv[0]
 * @c: line count
 * @cmd: input from user
 * @str: message
 * Return: void
 */
void _printe(char *filename, int c, char *cmd, char *str)
{
	_errorputs(filename);
	_errorputs(": ");
	print_number(c);
	_errorputs(": ");
	_errorputs(cmd);
	_errorputs(": ");
	_errorputs(str);
	_putchar('\n');
}

/**
 * print_number - print intgers
 * @n: integer number
 * Return:void
 */
void print_number(int n)
{
	unsigned int num, div_10, rem_10;

	if (n < 0)
	{
		num = -n;
		_putchar('-');
	}
	else
		num = n;

	div_10 = num / 10;
	rem_10 = num % 10;

	if (div_10)
		print_number(div_10);
	_putchar(rem_10 + 48);
}


