#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define PROMPT "$ "
#define ERROR_CODE 70
#define MAX_ARGS 20

/**
 * struct data_s - contains program data for easy access
 * @bytes: number of bytes read from getline
 * @process_no: process number
 * @buffer_length: length of the buffer read from getline
 * @cmd_args: command arguments
 * @buffer: string that store input from getline
 * @argv: list of arguments passed to the program
 */
typedef struct data_s
{
	ssize_t bytes;
	size_t buffer_length;
	int process_no;
	char *buffer;
	char **cmd_args;
	char **argv;
} data_t;

extern char **environ;

#define DATA_INIT                 \
	{                             \
		0, 0, 0, NULL, NULL, NULL \
	}

/* atoi.c */
int _atoi(const char *str);

/* builtins.c */
int is_builtin(data_t info);

/* check_cmd */
int check_cmd(data_t info);

/* memory.c */
void free_array(char **args);

/* errors.c */
void _print_error(data_t info);
void _print_atoi_error(data_t info);

/* write.c */
int _print(char *str);
int _eprint(char *str);

/* string.c */
int _strlen(const char *str);
char *_strdup(const char *str);
void num_to_string(char *str, int num);
int _strncmp(char *first_str, char *second_str, int n);

/* string2.c */
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char **split_string(char *buffer, char *delim);

/* exec_cmd.c */
void exec_cmd(data_t info);

/* path.c */
char *search_path(char *cmd);

#endif /* SHELL_H */
