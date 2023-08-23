#include "shell.h"

/**
 * shell_he - This for main shell loop
 * @info: onew the last teog gagien
 * @kll: may nothing the worsting
 *
 * @_fou: this four new
 * @info: qont onwqr onwqa
 * Return: feed is ret now ase
 */
int shell_he(info_t *info, char **mesa)
{
	ssize_t r = 0;
	int feed = 0;

	while (r != -1 && feed != -2)
	{
		_fou(info);
		if (_this_interactive(info))
			_puts("AE:)$ ");
		_shell_putchar_error(BU_EL);
		r = get_input(info);
		if (r != -1)
		{
			_infoma(info, mesa);
			feed = grab(info);
			if (feed == -1)
				grab_tza(info);
		}
		else if (_this_interactive(info))
			_putchar('\n');
		_let_info(info, 0);
	}
	_hiswrite(info);
	_let_info(info, 1);
	if (!_this_interactive(info) && info->mnlay)
		exit(info->mnlay);
	if (feed == -2)
	{
		if (info->numberoferror == -1)
			exit(info->mnlay);
		exit(info->numberoferror);
	}
	return (feed);
}

/**
 * ro_com - This for forks execution mybe
 *
 * @info: meregja ono nothginth thae
 *
 * Return: nothing in this time
 */
void ro_com(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->mengee, info->mesa, _botayge(info)) == -1)
		{
			_let_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->mnlay));
		if (WIFEXITED(info->mnlay))
		{
			info->mnlay = WEXITSTATUS(info->mnlay);
			if (info->mnlay == 126)
				_shell_error(info, "Permission denied\n");
		}
	}
}

/**
 * grab_tza - This for finds a command in menged
 *
 * @info: meregja ono it's no thae
 * Return: nothing in this time
 */
void grab_tza(info_t *info)
{
	char *mengee = NULL;
	int i, k;

	info->mengee = info->mesa[0];
	if (info->ccount_flag == 1)
	{
		info->coun_li++;
		info->ccount_flag = 0;
	}
	for (i = 0, k = 0; info->chec[i]; i++)
		if (!_this_delim(info->chec[i], " \t\n"))
			k++;
	if (!k)
		return;
	mengee = seek(info, yaze(info, "PATH="), info->mesa[0]);
	if (mengee)
	{
		info->mengee = mengee;
		ro_com(info);
	}
	else
	{
		if ((_this_interactive(info) || yaze(info, "PATH=") ||
			 info->mesa[0][0] == '/') &&
			_dete_com(info, info->mesa[0]))
			ro_com(info);
		else if (*(info->chec) != '\n')
		{
			info->mnlay = 127;
			_shell_error(info, "not found\n");
		}
	}
}
