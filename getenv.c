#include "shell.h"

/**
 * nont - This for initialize a new environment laiable
 * @info: onew onew opa onewq
 * @la: environment laiable onew
 * @value: environment laiable onewa
 * Return: 1 this time for ewns
 */

int nont(info_t *info, char *la, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *asl;

	if (!la || !value)
		return (0);

	buf = malloc(rzmet(la) + rzmet(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, la);
	agenagn(buf, "=");
	agenagn(buf, value);
	node = info->env;
	while (node)
	{
		asl = _ergata(node->str, la);
		if (asl && *asl == '=')
		{
			free(node->str);
			node->str = buf;
			info->aka_keyr = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->aka_keyr = 1;
	return (0);
}

/**
 * rem_env - This for removeing environment variable
 *
 * @info: environment laiable one wwne
 * @env_varia: one environment laiableon onwq
 *
 * Return: nothing inyu
 */
int rem_env(info_t *info, char *env_varia)
{
	list_t *node = info->env;
	size_t i = 0;
	char *asl;

	if (!node || !env_varia)
		return (0);

	while (node)
	{
		asl = _ergata(node->str, env_varia);
		if (asl && *asl == '=')
		{
			info->aka_keyr = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->aka_keyr);
}

/**
 * _botayge - This for return
 * @info: environment laiable onewqo nqqw
 *
 *
 * Return: this time akabai onewa
 */
char **_botayge(info_t *info)
{
	if (!info->akababi || info->aka_keyr)
	{
		info->akababi = zerzer_fi(info->env);
		info->aka_keyr = 0;
	}

	return (info->akababi);
}
