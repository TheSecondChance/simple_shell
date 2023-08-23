#include "shell.h"

/**
 * __maweda - This for comparison two strangs.

 * @has1: comp the one wawe newo
 * @has2: comp the one wawe newo
 * Return: tiem senln
 */
int __maweda(char *has1, char *has2)
{
	while (*has1 && *has2)
	{
		if (*has1 != *has2)
			return (*has1 - *has2);
		has1++;
		has2++;
	}
	if (*has1 == *has2)
		return (0);
	else
		return (*has1 < *has2 ? -1 : 1);
}

/**
 * rzmet - This for return len of str
 *
 * @fid: creaete one onae monwa
 * Return: count in this tiem senln
 */
int rzmet(char *fid)
{
	int count = 0;

	if (!fid)
		return (0);

	while (*fid++)
		count++;
	return (count);
}

/**
 * agenagn - This for concatenate two str
 *
 * @dest: cerea way to developed
 * @src: to main theone one black
 *
 * Return: mels this tiem senln
 */
char *agenagn(char *dest, char *src)
{
	char *mels = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (mels);
}

/**
 * _ergata - This for stable maddle maybe
 *
 * @haystack: to develope the that main
 * @needle: many what yor enw onwa nomw
 * Return: this tiem senln
 */
char *_ergata(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
