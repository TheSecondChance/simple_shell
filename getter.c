#include "shell.h"

/**
 * _let_info - This for let info struct field
 *
 * @info: environment laiable onwwq
 * @let: lon environment laiable onwq
 *
 * Return: nothing this
 */
void _let_info(info_t *info, int let)
{
	_let_it(info->mesa);
	info->mesa = NULL;
	info->mengee = NULL;
	if (let)
	{
		if (!info->str_cmd)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->tarik)
			free_list(&(info->tarik));
		if (info->alias)
			free_list(&(info->alias));
		_let_it(info->akababi);
		info->akababi = NULL;
		_let_buff((void **)info->str_cmd);
		if (info->read_tfi > 2)
			close(info->read_tfi);
		_putchar(BU_EL);
	}
}

/**
 * _infoma - This for initialize
 *
 * @info: environment laiable onwwq
 * @av: lon environment laiable onwq
 * Return: mere in this time
 */
void _infoma(info_t *info, char **av)
{
	int i = 0;

	info->tfi_de = av[0];
	if (info->arg)
	{
		info->mesa = tok_one(info->arg, " \t");
		if (!info->mesa)
		{
			info->mesa = malloc(sizeof(char *) * 2);
			if (info->mesa)
			{
				info->mesa[0] = _strdup(info->arg);
				info->mesa[1] = NULL;
			}
		}
		for (i = 0; info->mesa && info->mesa[i]; i++)
			;
		info->argc = i;

		_rep_ali(info);
		_rep_var(info);
	}
}

/**
 * _fou - This for initialize info struct
 *
 * @info: environment laiable onwwq
 * Return: nothing in this time
 */
void _fou(info_t *info)
{
	info->arg = NULL;
	info->mesa = NULL;
	info->mengee = NULL;
	info->argc = 0;
}
