#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the destination string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	dest[i + j] = '\0';
	return (dest);
}

/**
 * _strcpy - copies a string to another string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the destination string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * split_string - splits string into tokens
 * @buffer: string to split
 * @delim: delimiter
 *
 * Return: Array of splitted parts terminated by a NULL pointer
 */
char **split_string(char *buffer, char *delim)
{
	char *buf = NULL;
	char **parts = NULL;
	int i = 0;

	if (buffer == NULL)
	{
		return (NULL);
	}

	parts = malloc(sizeof(char *) * MAX_ARGS);
	if (parts == NULL)
	{
		return (NULL);
	}
	buf = strtok(buffer, delim);

	while (buf != NULL && i < MAX_ARGS - 1)
	{
		parts[i] = _strdup(buf);
		buf = strtok(NULL, delim);
		i++;
	}
	parts[i] = NULL;

	return (parts);
}

/**
 * _strcmp - compares two strings to check if they are equal
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if the strings are equal
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int len;
	int result = 0;

	if (_strlen(s1) >= _strlen(s2))
	{
		len = _strlen(s1);
	}
	else
	{
		len = _strlen(s2);
	}

	for (i = 0; i < len; i++)
	{
		if (s1[i] == s2[i])
		{
			continue;
		}
		else
		{
			result = s1[i] - s2[i];
			break;
		}
	}

	return (result);
}
