#include "shell.h"

/**
 * _putchar - This for writes character for this
 *
 * @c: char new meselegn enja
 * Return: 0 in this tiem senln
 */
int _putchar(char c)
{
	static int i;
	static char buf[WR_BU_SI];

	if (c == BU_EL || i >= WR_BU_SI)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BU_EL)
		buf[i++] = c;
	return (1);
}

/**
 * _strcpy - This for copies fidels
 *
 * @dest: char new maning the chear
 * @src: char new change view
 *
 * Return: 0 in this tiem senln
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _puts - This for input fidels
 *
 * @str: fid new meselegn enja
 * Return: nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _strdup - This for dupl str
 *
 * @str: fid new i thoug enja
 * Return: fid this tiem senln
 */
char *_strdup(const char *str)
{
	int mes = 0;
	char *fid;

	if (str == NULL)
		return (NULL);
	while (*str++)
		mes++;
	fid = malloc(sizeof(char) * (mes + 1));
	if (!fid)
		return (NULL);
	for (mes++; mes--;)
		fid[mes] = *--str;
	return (fid);
}
