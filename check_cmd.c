#include "shell.h"

/**
 * check_cmd - validates user commands
 * @info: a struct with program info
 *
 * Return: 1 if the command is valid, otherwise 0
 */
int check_cmd(data_t info)
{
	if (access(info.cmd_args[0], X_OK) == -1)
	{
		char *full_path = search_path(info.cmd_args[0]);

		if (full_path != NULL)
		{
			free(info.cmd_args[0]);
			info.cmd_args[0] = full_path;
			return (1);
		}
		else
		{
			_print_error(info);
			free_array(info.cmd_args);
			return (0);
		}
	}

	return (1);
}
