#include "shell.h"

/**
 * _print - prints string to stdout
 * @str: string to print
 *
 * Return: bytes printed
 */
int _print(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * _eprint - prints errors to stderr
 * @str: string to print
 *
 * Return: bytes printed
 */
int _eprint(char *str)
{
	return (write(STDERR_FILENO, str, _strlen(str)));
}
