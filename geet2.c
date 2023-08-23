#include "shell.h"
/**
 * _change - this for changes current directory of the process
 * @info: ther one onweee ononne now
 *
 *
 * Return: 1 in this time
 */
int _change(info_t *info)
{
	char *add, *dir, buffer[1024];
	int change_dir;

	add = getcwd(buffer, 1024);
	if (!add)
		_puts(">>Unable to retrieve the current working directory<<\n");
	if (!info->mesa[1])
	{
		dir = yaze(info, "HOME=");
		if (!dir)
			change_dir =
				chdir((dir = yaze(info, "PWD=")) ? dir : "/");
		else
			change_dir = chdir(dir);
	}
	else if (__maweda(info->mesa[1], "-") == 0)
	{
		if (!yaze(info, "OLDPWD="))
		{
			_puts(add);
			_putchar('\n');
			return (1);
		}
		_puts(yaze(info, "OLDPWD=")), _putchar('\n');
		change_dir =
			chdir((dir = yaze(info, "OLDPWD=")) ? dir : "/");
	}
	else
		change_dir = chdir(info->mesa[1]);
	if (change_dir == -1)
	{
		_shell_error(info, "can't cd to ");
		_shell_puts_error(info->mesa[1]), _shell_putchar_error('\n');
	}
	else
	{
		nont(info, "OLDPWD", yaze(info, "PWD="));
		nont(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _sense - test if current char in buffer
 *
 * @info: tine ow nipwp ieert onoo
 * @buf: one timn owe ninee
 * @asl: ein onr  ionop ww
 *
 * Return: 1 this time m
 */
int _sense(info_t *info, char *buf, size_t *asl)
{
	size_t j = *asl;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_type = VILM;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_type = FILS;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_type = SENSELET;
	}
	else
		return (0);
	*asl = j;
	return (1);
}
