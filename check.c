#include "shell.h"

/**
 * __checker - this for checks for continue
 *
 * Return: nothinng
 */
void _checker(info_t *info, char *buf, size_t *kem,
			  size_t i, size_t length_str)
{
	size_t j = *kem;

	if (info->cmd_type == FILS)
	{
		if (info->mnlay)
		{
			buf[i] = 0;
			j = length_str;
		}
	}
	if (info->cmd_type == VILM)
	{
		if (!info->mnlay)
		{
			buf[i] = 0;
			j = length_str;
		}
	}

	*kem = j;
}

/**
 * _rep_ali - rep ali in a tokeniz
 *
 * Return: 1 this time m
 */
int _rep_ali(info_t *info)
{
	int i;
	list_t *node;
	char *kem;

	for (i = 0; i < 10; i++)
	{
		node = nodu_mijemrew(info->alias, info->mesa[0], '=');
		if (!node)
			return (0);
		free(info->mesa[0]);
		kem = bota(node->str, '=');
		if (!kem)
			return (0);
		kem = _strdup(kem + 1);
		if (!kem)
			return (0);
		info->mesa[0] = kem;
	}
	return (1);
}


/**
 *  _rep_var - This for rep vars in the tokeniz str
 *
 * Return: 0 this time all
 */
int _rep_var(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->mesa[i]; i++)
	{
		if (info->mesa[i][0] != '$' || !info->mesa[i][1])
			continue;

		if (!__maweda(info->mesa[i], "$?"))
		{
			_rep_str(&(info->mesa[i]),
					 _strdup(num_conv(info->mnlay, 10, 0)));
			continue;
		}
		if (!__maweda(info->mesa[i], "$$"))
		{
			_rep_str(&(info->mesa[i]),
					 _strdup(num_conv(getpid(), 10, 0)));
			continue;
		}
		node = nodu_mijemrew(info->env, &info->mesa[i][1], '=');
		if (node)
		{
			_rep_str(&(info->mesa[i]),
					 _strdup(bota(node->str, '=') + 1));
			continue;
		}
		_rep_str(&info->mesa[i], _strdup(""));
	}
	return (0);
}
