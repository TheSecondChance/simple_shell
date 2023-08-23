#include "shell.h"

/**
 * _dete_com - This for determine if file
 *
 * Return: noting in this time,
 */
int _dete_com(info_t *info, char *mengee)
{
	struct stat st;

	(void)info;
	if (!mengee || stat(mengee, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * seek - This for finds a cmd in mengee fidels
 *
 * Return: nothing if function not work
 */
char *seek(info_t *info, char *str_seek, char *cmd)
{
	int i = 0, po_cu = 0;
	char *mengee;

	if (!str_seek)
		return (NULL);
	if ((rzmet(cmd) > 2) && _ergata(cmd, "./"))
	{
		if (_dete_com(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!str_seek[i] || str_seek[i] == ':')
		{
			mengee = character_dup(str_seek, po_cu, i);
			if (!*mengee)
				agenagn(mengee, cmd);
			else
			{
				agenagn(mengee, "/");
				agenagn(mengee, cmd);
			}
			if (_dete_com(info, mengee))
				return (mengee);
			if (!str_seek[i])
				break;
			po_cu = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * character_dup - This for duplicate characters
 *
 * Return: buff mya not core onw,
 */
char *character_dup(char *str_seek, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (str_seek[i] != ':')
			buf[k++] = str_seek[i];
	buf[k] = 0;
	return (buf);
}
