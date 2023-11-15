#include "shell.h"

/**
 * exec_cmd - executes the command
 * @info: a struct with program info
 */
void exec_cmd(data_t info)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(info.argv[0]);
		exit(-1);
	}
	if (child_pid == 0)
	{
		execve(info.cmd_args[0], info.cmd_args, environ);
		perror(info.argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		errno = status;
		free_array(info.cmd_args);
	}
}
