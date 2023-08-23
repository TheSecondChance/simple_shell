#include "shell.h"

/**
 * _shell_puts_file - This for prints input fidels
 * Return: fid not one for ewan
 */
int _shell_puts_file(char *fidels, int shell_d)
{
	int i = 0;

	if (!fidels)
		return (0);
	while (*fidels)
	{
		i += _shell_p_file(*fidels++, shell_d);
	}
	return (i);
}



/**
 * _shell_p_file - this for writes the character c
 * Return: 1 this time for ewns
 */
int _shell_p_file(char c, int shell_d)
{
	static int i;
	static char buf[WR_BU_SI];

	if (c == BU_EL || i >= WR_BU_SI)
	{
		write(shell_d, buf, i);
		i = 0;
	}
	if (c != BU_EL)
		buf[i++] = c;
	return (1);
}

/**
 * __error_puts - prints an input fidels to stderr
 * Return: nothing this time ewns
 */
void _shell_puts_error(char *fid)
{
	int i = 0;

	if (!fid)
		return;
	while (fid[i] != '\0')
	{
		_shell_putchar_error(fid[i]);
		i++;
	}
}
/**
 * _shell_putchar_error - This for writes a character
 * Return: 1 this time for ewns
 */
int _shell_putchar_error(char c)
{
	static int i;
	static char buf[WR_BU_SI];

	if (c == BU_EL || i >= WR_BU_SI)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BU_EL)
		buf[i++] = c;
	return (1);
}
