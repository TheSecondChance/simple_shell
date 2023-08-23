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

/**
 * convert - This for fidels to an int
 *
 * Return: 1 in this time
 */

int convert(char *ql)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; ql[i] != '\0' && flag != 2; i++)
	{
		if (ql[i] == '-')
			sign *= -1;

		if (ql[i] >= '0' && ql[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (ql[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
/**
 * _this_interactive - This for returns true mode intractive
 *
 * Return: 1 in this time,
 */
int _this_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->read_tfi <= 2);
}
