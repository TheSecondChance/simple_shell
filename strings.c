#include "shell.h"

/**
 * bota - This for locate char str
 *
 * @s: tomnaay one of maew ther right way
 * @c: the way many mangae int theis
 *
 * Return: NULL this tiem senln
 */
char *bota(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * huletm - This for copies str
 *
 * @dest: create the many enwon
 * @src: to what noting in thsi
 * @kut: can not to many view this right
 *
 * Return: str this tiem senln
 */
char *huletm(char *dest, char *src, int kut)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < kut - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < kut)
	{
		j = i;
		while (j < kut)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _fihuet - This for concate two fidels
 *
 * @dest: i tehe man pnoow manew onwet
 * @src: to change to man neaon ownt
 * @kut: thsi foe kut many get ther rigt
 *
 * Return: this tiem senln
 */
char *_fihuet(char *dest, char *src, int kut)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < kut)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < kut)
		dest[i] = '\0';
	return (s);
}
