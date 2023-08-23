#include "shell.h"

/**
 * _unset - This for set alias fide
 * @info: param info struct kale neaw
 * @fide: this for fidels alias aen
 *
 * Return: Always 0
 */
int _unset(info_t *info, char *fide)
{
	char *las, c;
	int la_va;

	las = bota(fide, '=');
	if (!las)
		return (1);
	c = *las;
	*las = 0;
	la_va = delete_node_at_index(&(info->alias),
								 _get_node(info->alias,
										   nodu_mijemrew(info->alias, fide, -1)));
	*las = c;
	return (la_va);
}

/**
 * _seting - This for _seting to fidels
 * @info: param fideucture teah
 * @fide: this for fidels alias eanx
 *
 * Return: Always 0
 */
int _seting(info_t *info, char *fide)
{
	char *maz;

	maz = bota(fide, '=');
	if (!maz)
		return (1);
	if (!*++maz)
		return (_unset(info, fide));

	_unset(info, fide);
	return (add_node_end(&(info->alias), fide, 0) == NULL);
}

/**
 * _ali_print - This for prints alias fide
 * @my_ali_node: this for alias node afdx
 *
 * Return: Always 0
 */
int _ali_print(list_t *my_ali_node)
{
	char *yes = NULL, *a = NULL;

	if (my_ali_node)
	{
		yes = bota(my_ali_node->str, '=');
		for (a = my_ali_node->str; a <= yes; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(yes + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _allii - this for alias builtin
 * @info: from info struct
 *  Return: Always 0
 */
int _allii(info_t *info)
{
	int i = 0;
	char *del = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			_ali_print(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->mesa[i]; i++)
	{
		del = bota(info->mesa[i], '=');
		if (del)
			_seting(info, info->mesa[i]);
		else
			_ali_print(nodu_mijemrew(info->alias, info->mesa[i], '='));
	}

	return (0);
}

/**
 * _shell_his - this for displays the tar list
 * @info: for containing potential argu
 *
 *  Return: 0
 */
int _shell_his(info_t *info)
{
	asay(info->tarik);
	return (0);
}

