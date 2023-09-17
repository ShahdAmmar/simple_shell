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

/**
 * _strdup - copies the string to another variable
 * @str: constant string
 * Return: ptr to copied string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *cp_str;

	if (!str)
		return (NULL);
	while (*str++)
		len++;

	cp_str = malloc(sizeof(char) * (len + 1));
	if (!cp_str)
		return (NULL);
	for (len++; len--;)
		cp_str[len] = *--str;

	return (cp_str);
}

/**
 * _strcmp - compare 2 strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0, 1, or -1
 */
int _strcmp(char *s1, char *s2)
{
	int diff;

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			diff = *s1 - *s2;
			return (diff);
		}
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else if (*s1 < *s2)
		return (-1);
	else
		return (1);
}
