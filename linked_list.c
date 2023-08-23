#include "shell.h"



/**
 * zerzer_fi - This for returns an array of the list str
 * @wana_node: new nll oewa ponewoni oiywer
 *
 * Return: fide int this time
 */
char **zerzer_fi(list_t *wana_node)
{
	list_t *node = wana_node;
	size_t i = zerzer(wana_node), j;
	char *str;
	char **fidd;

	if (!wana_node || !i)
		return (NULL);
	fidd = malloc(sizeof(char *) * (i + 1));
	if (!fidd)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(rzmet(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(fidd[j]);
			free(fidd);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		fidd[i] = str;
	}
	fidd[i] = NULL;
	return (fidd);
}

/**
 * _get_node - This for get the index of node
 *
 * @main: one the onelae lwet qqwe nwq
 * @ode: ons mine ii maint awonw ownqa
 *
 * Return: -1 if parameter is t
 */
ssize_t _get_node(list_t *main, list_t *ode)
{
	size_t i = 0;

	while (main)
	{
		if (main == ode)
			return (i);
		main = main->next;
		i++;
	}
	return (-1);
}

/**
 * nodu_mijemrew - This for returns node whose fidels starts with ketach
 *
 * @node: rtut whose fiedde owne
 * @ketach: mbc ine pone awer onwl
 * @c: char onew chaonew mon none od
 *
 * Return: NULL in this time aen
 */
list_t *nodu_mijemrew(list_t *node, char *ketach, char c)
{
	char *lia = NULL;

	while (node)
	{
		lia = _ergata(node->str, ketach);
		if (lia && ((c == -1) || (*lia == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * asay - This for prints all elements of a list_t linked list
 *
 * @first: noet inwe mmie waonew
 * Return: noting in this time,
 */
size_t asay(const list_t *first)
{
	size_t i = 0;

	while (first)
	{
		_puts(num_conv(first->kutre, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(first->str ? first->str : "(nil)");
		_puts("\n");
		first = first->next;
		i++;
	}
	return (i);
}
/**
 * zerzer - This for determine len a linked list
 * @first: noet inwe mmie waonew
 *
 * Return: noting in this time,
 */
size_t zerzer(const list_t *first)
{
	size_t i = 0;

	while (first)
	{
		first = first->next;
		i++;
	}
	return (i);
}
