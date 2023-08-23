#include "shell.h"

/**
 * _conve - This for converts a fidels to an integer
 *
 * Return: res for ewan
 */
int _conve(char *fidels)
{
	int i = 0;
	unsigned long int res = 0;

	if (*fidels == '+')
		fidels++;
	for (i = 0; fidels[i] != '\0'; i++)
	{
		if (fidels[i] >= '0' && fidels[i] <= '9')
		{
			res *= 10;
			res += (fidels[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
/**
 * com_rem - this for replaces function
 *
 * Return: nothing this time m
 */
void com_rem(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

/**
 * _deci_pri - This for function prints a decimal
 *
 * Return: count for ewan
 */
int _deci_pri(int input, int tfi_de)
{
	int (*_ymesla)(char) = _putchar;
	int i, coun = 0;
	unsigned int _solute_, curr;

	if (tfi_de == STDERR_FILENO)
		_ymesla = _shell_putchar_error;
	if (input < 0)
	{
		_solute_ = -input;
		_ymesla('-');
		coun++;
	}
	else
		_solute_ = input;
	curr = _solute_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_solute_ / i)
		{
			_ymesla('0' + curr / i);
			coun++;
		}
		curr %= i;
	}
	_ymesla('0' + curr);
	coun++;

	return (coun);
}



/**
 * _shell_error - This for prints error message
 *
 * Return: nothing for ewan
 */
void _shell_error(info_t *info, char *error_str)
{
	_shell_puts_error(info->tfi_de);
	_shell_puts_error(": ");
	_deci_pri(info->coun_li, STDERR_FILENO);
	_shell_puts_error(": ");
	_shell_puts_error(info->mesa[0]);
	_shell_puts_error(": ");
	_shell_puts_error(error_str);
}

/**
 * num_conv - This for converter function
 *
 * Return: str owal nwan
 */
char *num_conv(long int kutre, int bases, int unta)
{
	static char *arr_char;
	static char buffer[50];
	char sign = 0;
	char *amel;
	unsigned long n = kutre;

	if (!(unta & YALTMEKE) && kutre < 0)
	{
		n = -kutre;
		sign = '-';
	}
	arr_char = unta & FIDELME ? "0123456789abcdef" : "0123456789ABCDEF";
	amel = &buffer[49];
	*amel = '\0';

	do
	{
		*--amel = arr_char[n % bases];
		n /= bases;
	} while (n != 0);

	if (sign)
		*--amel = sign;
	return (amel);
}
