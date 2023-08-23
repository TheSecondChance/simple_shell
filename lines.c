#include "shell.h"

/**
 * buffer_input - This for buffers chained commands
 * @info: onw one oow qqwe nwq
 * @buf: ons onwq awonw ownqa
 * @meth: onew onne asdow
 *
 * Return: 1 this time for ewns
 *  * this for buffer
 * changin
 * commans
 * thsi srewt own lshell
 * createtd by ther onwert awetn
 * nowt monewa good listing
 * rewt wayt ot develpe
 * this hard to lke int
 * many of
 */
ssize_t buffer_input(info_t *info, char **buf, size_t *meth)
{
	ssize_t r = 0;
	size_t meth_p = 0;

	if (!*meth)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, _handle_block);
#if SYS_GET
		r = ketay_mes(buf, &meth_p, stdin);
#else
		r = ketay_mes(info, buf, &meth_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->ccount_flag = 1;
			com_rem(*buf);
			_lis_his_buil(info, *buf, info->stor_coun++);
			{
				*meth = r;
				info->str_cmd = buf;
			}
		}
	}
	return (r);
}

/**
 * buff_re - This for reads a buffer
 *
 * @info: onw one oow qqwe nwq
 * @buf: ons onwq awonw ownqa
 * @i: onew onne asdow
 * Return: random tn oube nome
 */
ssize_t buff_re(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->read_tfi, buf, RE_SIZ_BUFE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _handle_block - this for blocks ctrl-C
 * @nu_sig: de onew owaponke kone onwq
 *
 * Return: ntog this time for ewns
 */
void _handle_block(__attribute__((unused)) int nu_sig)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BU_EL);
}
/**
 * ketay_mes - this for get the next line of input
 *
 * @info: onw one oow qqwe nwq bvxz
 * @amel: ons onwq awonw ownqa  waw
 * @length: onew onne asdow ytn
 *
 * Return: nothing ade sew newo
 */
int ketay_mes(info_t *info, char **amel, size_t *length)
{
	static char buf[RE_SIZ_BUFE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *onea = NULL, *new_p = NULL, *c;

	onea = *amel;
	if (onea && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = buff_re(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = bota(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _calloc(onea, s, s ? s + k : k + 1);
	if (!new_p)
		return (onea ? free(onea), -1 : -1);

	if (s)
		_fihuet(new_p, buf + i, k - i);
	else
		huletm(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	onea = new_p;

	if (length)
		*length = s;
	*amel = onea;
	return (s);
}

/**
 * get_input - This for get line
 * @info: onwo wetta twqw
 * Return: ewns man fame neq onea
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t i, j, meth;
	ssize_t r = 0;
	char **buf_p = &(info->chec), *lia;

	_putchar(BU_EL);
	r = buffer_input(info, &buf, &meth);
	if (r == -1)
		return (-1);
	if (meth)
	{
		j = i;
		lia = buf + i;

		_checker(info, buf, &j, i, meth);
		while (j < meth)
		{
			if (_sense(info, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= meth)
		{
			i = meth = 0;
			info->cmd_type = CMD_CURRENT;
		}

		*buf_p = lia;
		return (rzmet(lia));
	}

	*buf_p = buf;
	return (r);
}
