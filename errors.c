#include "shell.h"

/**
 * _print_error - prints errors to stdin
 * @info: a struct with program info
 */
void _print_error(data_t info)
{
	char process[4];

	num_to_string(process, info.process_no);
	_eprint(info.argv[0]);
	_eprint(": ");
	_eprint(process);
	_eprint(": ");
	_eprint(info.argv[0]);
	_eprint(": not found\n");
}

/**
 * _print_atoi_error - prints errors to stdin
 * @info: a struct with program info
 */
void _print_atoi_error(data_t info)
{
	char process[4];

	num_to_string(process, info.process_no);
	_eprint(info.argv[0]);
	_eprint(": ");
	_eprint(process);
	_eprint(": ");
	_eprint(info.cmd_args[0]);
	_eprint(": Illegal number: ");
	_eprint(info.cmd_args[1]);
	_eprint("\n");
}
