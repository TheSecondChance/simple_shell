#include "shell.h"

/**
 * free_list - This for free all nodes of a list
 *
 * Return: nothing in this time
 */
void free_list(list_t **mejem_pt)
{
	list_t *node, *next_node, *head;

	if (!mejem_pt || !*mejem_pt)
		return;
	head = *mejem_pt;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*mejem_pt = NULL;
}


/**
 * delete_node_at_index - This for deletes node given index
 *
 * Return: nothing one oqw awe tla
 */
int delete_node_at_index(list_t **kelay, unsigned int index)
{
	list_t *node, *meem_node;
	unsigned int i = 0;

	if (!kelay || !*kelay)
		return (0);

	if (!index)
	{
		node = *kelay;
		*kelay = (*kelay)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *kelay;
	while (node)
	{
		if (i == index)
		{
			meem_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		meem_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * add_node - This for adds node to the start
 *
 * Return: wana_node in this tiem lan
 */
list_t *add_node(list_t **kelay, const char *str, int num)
{
	list_t *wana_node;

	if (!kelay)
		return (NULL);
	wana_node = malloc(sizeof(list_t));
	if (!wana_node)
		return (NULL);
	_constmem((void *)wana_node, 0, sizeof(list_t));
	wana_node->kutre = num;
	if (str)
	{
		wana_node->str = _strdup(str);
		if (!wana_node->str)
		{
			free(wana_node);
			return (NULL);
		}
	}
	wana_node->next = *kelay;
	*kelay = wana_node;
	return (wana_node);
}

/**
 * fidelas - This for prints only the fidels element
 *
 * Return: not oen  owa leer noew,
 */
size_t fidelas(const list_t *mejem_pt)
{
	size_t i = 0;

	while (mejem_pt)
	{
		_puts(mejem_pt->str ? mejem_pt->str : "(nil)");
		_puts("\n");
		mejem_pt = mejem_pt->next;
		i++;
	}
	return (i);
}
