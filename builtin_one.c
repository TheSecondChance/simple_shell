#include "shell.h"

/**
 * _exit_shell - This for exit to shell
 * Return: 1 in this time
 */
int _exit_shell(info_t *info)
{
	int check_exit_shell;

	if (info->mesa[1])
	{
		check_exit_shell = _conve(info->mesa[1]);
		if (check_exit_shell == -1)
		{
			info->mnlay = 2;
			_shell_error(info, "Illegal number: ");
			_shell_puts_error(info->mesa[1]);
			_shell_putchar_error('\n');
			return (1);
		}
		info->numberoferror = _conve(info->mesa[1]);
		return (-2);
	}
	info->numberoferror = -1;
	return (-2);
}



/**
 * _current - This for changes current directory of the process
 * Return: 1 in this time
 */
int _current(info_t *info)
{
	char **argument_array;

	argument_array = info->mesa;
	_puts("Please refer to the official documentation sites for GNU or C\n");
	if (0)
		_puts(*argument_array);
	return (0);
}
