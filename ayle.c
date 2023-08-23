#include "shell.h"

/**
 * __thealpha -  This for checks alphabetic char
 *
 * Return: 1 in this time
 */

int __thealpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _this_delim - This fore checks character is delimeter
 *
 * Return: 0 in this time kab
 */
int _this_delim(char fi, char *delim)
{
	while (*delim)
		if (*delim++ == fi)
			return (1);
	return (0);
}
