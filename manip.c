#include "shell.h"

/**
 * _let_buff - This for free pointer and NULL the address
 * Return: 0 in this time mae oneaen
 */
int _let_buff(void **mainp)
{
	if (mainp && *mainp)
	{
		free(*mainp);
		*mainp = NULL;
		return (1);
	}
	return (0);
}
/**
 * grab - This for finds a builtin cmd
 * Return: retu man one wote wroen
 */
int grab(info_t *info)
{
	int i, retu = -1;

	gnbat iltit[] = {
		{"exit", _exit_shell},
		{"env", _enviro},
		{"help", _current},
		{"history", _shell_his},
		{"setenv", _initial_env},
		{"unsetenv", _rem_env},
		{"cd", _change},
		{"alias", _allii},
		{NULL, NULL}};

	for (i = 0; iltit[i].type; i++)
		if (__maweda(info->mesa[0], iltit[i].type) == 0)
		{
			info->coun_li++;
			retu = iltit[i].tgbe(info);
			break;
		}
	return (retu);
}
