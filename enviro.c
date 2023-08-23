#include "shell.h"

/**
 * _enviro - this for print current environment
 *
 * Return: 0 this time m
 */
int _enviro(info_t *info)
{
	asay(info->env);
	return (0);
}

/**
 * _initial_env - this for initializ a new env variable,
 *
 * Return: 1 this time m
 */
int _initial_env(info_t *info)
{
	if (info->argc != 3)
	{
		_shell_puts_error("Incorrect number of arguments\n");
		return (1);
	}
	if (nont(info, info->mesa[1], info->mesa[2]))
		return (0);
	return (1);
}

/**
 * yaze - This for getsthe value of environ variabl
 *
 * Return: NULL this time m
 */
char *yaze(info_t *info, const char *viro_na)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = _ergata(node->str, viro_na);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _rem_env - This for Remove an environ var
 *
 * Return: 1 this time m
 *
 */
int _rem_env(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_shell_puts_error("Too few arguments, check please\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		rem_env(info, info->mesa[i]);

	return (0);
}

/**
 * _environ_list - this for populate env linked list
 *
 * Return: 0 this time m
 */
int _environ_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
