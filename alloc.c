#include "shell.h"

/**
 * _calloc - This for realloc block of memory space
 *
 * Return: add the right time of aefn
 */
void *_calloc(void *amel, unsigned int curr, unsigned int curr_size)
{
	char *ad;

	if (!amel)
		return (malloc(curr_size));
	if (!curr_size)
		return (free(amel), NULL);
	if (curr_size == curr)
		return (amel);

	ad = malloc(curr_size);
	if (!ad)
		return (NULL);

	curr = curr < curr_size ? curr : curr_size;
	while (curr--)
		ad[curr] = ((char *)amel)[curr];
	free(amel);
	return (ad);
}

/**
 * _constmem - This for fill memory with constant
 *
 * Return: fid in this tiem aemo
 */
char *_constmem(char *fid, char co_byt, unsigned int c)
{
	unsigned int i;

	for (i = 0; i < c; i++)
		fid[i] = co_byt;
	return (fid);
}

/**
 * _let_it - This fore frees fidels of fidels
 *
 * Return: en not one of same thing
 */
void _let_it(char **fidels)
{
	char **en = fidels;

	if (!fidels)
		return;
	while (*fidels)
		free(*fidels++);
	free(en);
}
