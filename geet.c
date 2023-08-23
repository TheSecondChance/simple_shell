#include "shell.h"
/**
 * _rep_str - rep string
 * Return: 1 this time m
 */
int _rep_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
/**
 * _lis_his_buil - This for adds new entry
 * Return: 0 in this time
 */
int _lis_his_buil(info_t *info, char *buf, int coun_li)
{
	list_t *node = NULL;

	if (info->tarik)
		node = info->tarik;
	add_node_end(&node, buf, coun_li);

	if (!info->tarik)
		info->tarik = node;
	return (0);
}

/**
 * add_node_end - adds a node to the end of the list
 * Return: adis not my one a le onll
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *adis, *node;

	if (!head)
		return (NULL);

	node = *head;
	adis = malloc(sizeof(list_t));
	if (!adis)
		return (NULL);
	_constmem((void *)adis, 0, sizeof(list_t));
	adis->kutre = num;
	if (str)
	{
		adis->str = _strdup(str);
		if (!adis->str)
		{
			free(adis);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = adis;
	}
	else
		*head = adis;
	return (adis);
}
