#include "shell.h"

/**
 * main - This for entry point
 *
 * @chek: my onew;onvone
 * @sbe: one iewin ow onewwe nee
 * Return: success my notas
 */
int main(int chek, char **sbe)
{
	info_t info[] = {MASGEMER};
	int dirct = 2;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(dirct)
		: "r"(dirct));

	if (chek == 2)
	{
		dirct = open(sbe[1], O_RDONLY);
		if (dirct == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_shell_puts_error(sbe[0]);
				_shell_puts_error(": 0: Can't open ");
				_shell_puts_error(sbe[1]);
				_shell_putchar_error('\n');
				_shell_putchar_error(BU_EL);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->read_tfi = dirct;
	}
	_environ_list(info);
	_his_rea(info);
	shell_he(info, sbe);
	return (EXIT_SUCCESS);
}
