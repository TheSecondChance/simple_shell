#include "shell.h"

/**
 * _tok - This for splits fidels into words
 * @str: onw one oow qqwe nwq
 * @on: ons onwq awonw ownqa
 * Return: fidels int the first
 */
char **_tok(char *str, char on)
{
	int i, j, k, m, fide = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != on && str[i + 1] == on) ||
			(str[i] != on && !str[i + 1]) || str[i + 1] == on)
			fide++;
	if (fide == 0)
		return (NULL);
	s = malloc((1 + fide) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < fide; j++)
	{
		while (str[i] == on && str[i] != on)
			i++;
		k = 0;
		while (str[i + k] != on && str[i + k] && str[i + k] != on)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **tok_one - This for splits fidels into words
 * @str: onw one oow qqwe nwq
 * @kae: ons onwq awonw ownqa
 * Return: fidels int the first
 */

char **tok_one(char *str, char *kae)
{
	int i, un, k, m, fide = 0;
	char **ta;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!kae)
		kae = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!_this_delim(str[i], kae) && (_this_delim(str[i + 1], kae)
					|| !str[i + 1]))
			fide++;

	if (fide == 0)
		return (NULL);
	ta = malloc((1 + fide) * sizeof(char *));
	if (!ta)
		return (NULL);
	for (i = 0, un = 0; un < fide; un++)
	{
		while (_this_delim(str[i], kae))
			i++;
		k = 0;
		while (!_this_delim(str[i + k], kae) && str[i + k])
			k++;
		ta[un] = malloc((k + 1) * sizeof(char));
		if (!ta[un])
		{
			for (k = 0; k < un; k++)
				free(ta[k]);
			free(ta);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			ta[un][m] = str[i++];
		ta[un][m] = 0;
	}
	ta[un] = NULL;
	return (ta);
}
