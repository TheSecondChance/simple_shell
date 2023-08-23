#include "shell.h"

/**
 * _rehistory - This for renumbers the history linked list
 *
 * Return: mereja meselegn enja
 */
int _rehistory(info_t *info)
{
	list_t *node = info->tarik;
	int i = 0;

	while (node)
	{
		node->kutre = i++;
		node = node->next;
	}
	return (info->stor_coun = i);
}

/**
 * _hiswrite - This for writes to file history
 *
 * Return: mereja meselegn enja
 */
int _hiswrite(info_t *info)
{
	ssize_t dirct;
	char *tfi_de = fil_his_get(info);
	list_t *node = NULL;

	if (!tfi_de)
		return (-1);

	dirct = open(tfi_de, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(tfi_de);
	if (dirct == -1)
		return (-1);
	for (node = info->tarik; node; node = node->next)
	{
		_shell_puts_file(node->str, dirct);
		_shell_p_file('\n', dirct);
	}
	_shell_p_file(BU_EL, dirct);
	close(dirct);
	return (1);
}



/**
 * fil_his_get - This for get the file history
 *
 * Return: buffer in this time
 */

char *fil_his_get(info_t *info)
{
	char *buf, *ath_file;

	ath_file = yaze(info, "HOME=");
	if (!ath_file)
		return (NULL);
	buf = malloc(sizeof(char) * (rzmet(ath_file) + rzmet(FIL_HI) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, ath_file);
	agenagn(buf, "/");
	agenagn(buf, FIL_HI);
	return (buf);
}

/**
 * _his_rea - This for read a history
 *
 * Return: mereja in this time
 */
int _his_rea(info_t *info)
{
	int i, last = 0, mes_kut = 0;
	ssize_t dirct, len_red, dirce_si = 0;
	struct stat st;
	char *buf = NULL, *filename = fil_his_get(info);

	if (!filename)
		return (0);

	dirct = open(filename, O_RDONLY);
	free(filename);
	if (dirct == -1)
		return (0);
	if (!fstat(dirct, &st))
		dirce_si = st.st_size;
	if (dirce_si < 2)
		return (0);
	buf = malloc(sizeof(char) * (dirce_si + 1));
	if (!buf)
		return (0);
	len_red = read(dirct, buf, dirce_si);
	buf[dirce_si] = 0;
	if (len_red <= 0)
		return (free(buf), 0);
	close(dirct);
	for (i = 0; i < dirce_si; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			_lis_his_buil(info, buf + last, mes_kut++);
			last = i + 1;
		}
	if (last != i)
		_lis_his_buil(info, buf + last, mes_kut++);
	free(buf);
	info->stor_coun = mes_kut;
	while (info->stor_coun-- >= XA_HIS)
		delete_node_at_index(&(info->tarik), 0);
	_rehistory(info);
	return (info->stor_coun);
}
