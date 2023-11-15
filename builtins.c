#include "shell.h"

/**
 * print_env - prints environment variables
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_print(environ[i]);
		_print("\n");
		i++;
	}
}

/**
 * is_builtin - checks and executes builtin functions
 * @info: a struct containing program info
 *
 * Return: 1 if it command matches inbuilt command
 */
int is_builtin(data_t info)
{
	int status = 0;

	if (_strcmp(info.cmd_args[0], "exit") == 0)
	{
		if (info.cmd_args[1])
		{
			status = _atoi(info.cmd_args[1]);
			if (status == -1)
			{
				errno = 2;
				_print_atoi_error(info);
				info.process_no += 1;
				free_array(info.cmd_args);
				return (1);
			}
			free(info.buffer);
			free_array(info.cmd_args);
			exit(status % 256);
		}
		free(info.buffer);
		free_array(info.cmd_args);
		exit(errno);
	}
	if (_strcmp(info.cmd_args[0], "env") == 0)
	{
		print_env();
		free_array(info.cmd_args);
		info.process_no += 1;
		status = 1;
	}
	return (status);
}
