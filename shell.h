#ifndef __ALEEYA_SHELL_H__
#define __ALEEYA_SHELL_H__

/* This For Librari Zere*/
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

/* Zerezer */
#define WR_BU_SI 1024
#define RE_SIZ_BUFE 1024
#define BU_EL -1

/* Define yemike zerw */
#define FILS 2
#define VILM 1
#define SENSELET 3
#define CMD_CURRENT 0

/* Gelest for Geonnw one */
#define FIDELME 1
#define YALTMEKE 2

/* Endehunetaw for using system gnoe */
#define SYS_SET 0

#define SYS_GET 0
#define XA_HIS 4096
#define FIL_HI ".simple_shell_history"


extern char **environ;

/**
 * struct zerz - This for singly linked list
 * @kutre: the kutre field
 * @str: a fidels
 * @next: points to the next node
 */
typedef struct zerz
{
	int kutre;
	char *str;
	struct zerz *next;
} list_t;

/**
 * struct kargument - This for contain karguementsd aef
 * @chec: fidels from getline containing argfds
 * @mesa:an fidels vector for this asdf
 * @mengee: a mengee for the current one aswq
 * @argc: awt itye count containing ewef
 * @coun_li: the line count for this ase
 * @numberoferror: the error code to check numberwea
 * @ccount_flag: flags attached to lineaasd yewd
 * @tfi_de: the program filename  attached aey
 * @env: linked list local copy system dwyh
 * @akababi: custom modified copy of akababi from attached asde
 * @alias: ytr5 node ionted onew yo eha
 * @tarik: tarik node ionted rqds asf
 * @aka_keyr: checks if aka_keyr variable for newa a dnf
 * @mnlay: the return mnlay of the last command in this aef
 * @str_cmd: jytr of pointer to cmd_buffer command eaeu
 * @cmd_type: CMD_type, either awky lopy this mean itrs
 * @read_tfi: The directory of the file from which to read line input hrea
 * @stor_coun: The count of line numbers in the history rer fsa
 */
typedef struct kargument
{
	unsigned int coun_li;
	char *arg;
	char **mesa;
	char *mengee;
	int argc;
	int numberoferror;
	int ccount_flag;
	char *tfi_de;
	list_t *env;
	list_t *alias;
	list_t *tarik;
	char **akababi;
	int aka_keyr;
	int mnlay;

	char **str_cmd;
	int cmd_type;
	int read_tfi;
	int stor_coun;
} info_t;

/* MEREJA MASJEMER*/
#define MASGEMER                                                                             \
	{                                                                                    \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL,      \
			0, 0, 0                                                              \
	}

/**
 * struct builtin - This for contains a builtin str
 * @type: the builtin command flag asdfe
 * @tgbe: for the tgbe
 */
typedef struct builtin
{
	char *type;
	int (*tgbe)(info_t *);
} gnbat;

void ro_com(info_t *);
void grab_tza(info_t *);
int grab(info_t *);
int shell_he(info_t *, char **);
char *character_dup(char *, int, int);
char *seek(info_t *, char *, char *);
int _dete_com(info_t *, char *);
int _shell_p_file(char c, int fd);
void _shell_puts_error(char *);
int _shell_puts_file(char *str, int fd);
int _shell_putchar_error(char);
char *_ergata(const char *, const char *);
int rzmet(char *);
char *agenagn(char *, char *);
int __maweda(char *, char *);
char *_strdup(const char *);
char *_strcpy(char *, char *);
int _putchar(char);
void _puts(char *);
int _lis_his_buil(info_t *info, char *buf, int coun_li);
char *fil_his_get(info_t *info);
int _his_rea(info_t *info);
int _rehistory(info_t *info);
int _hiswrite(info_t *info);
int delete_node_at_index(list_t **, unsigned int);
list_t *add_node(list_t **, const char *, int);
size_t fidelas(const list_t *);
void free_list(list_t **);
list_t *add_node_end(list_t **, const char *, int);
size_t asay(const list_t *);
list_t *nodu_mijemrew(list_t *, char *, char);
size_t zerzer(const list_t *);
ssize_t _get_node(list_t *, list_t *);
char **zerzer_fi(list_t *);
int _sense(info_t *, char *, size_t *);
int _rep_var(info_t *);
int _rep_ali(info_t *);
int _rep_str(char **, char *);
void _checker(info_t *, char *, size_t *, size_t, size_t);
char *_fihuet(char *, char *, int);
char *huletm(char *, char *, int);
char *bota(char *, char);
char **_tok(char *, char);
char **tok_one(char *, char *);
void _let_it(char **);
char *_constmem(char *, char, unsigned int);
void *_calloc(void *, unsigned int, unsigned int);
int _let_buff(void **);
int __thealpha(int);
int _this_interactive(info_t *);
int convert(char *);
int _this_delim(char, char *);
int _deci_pri(int, int);
int _conve(char *);
char *num_conv(long int, int, int);
void com_rem(char *);
void _shell_error(info_t *, char *);
int _exit_shell(info_t *);
int _current(info_t *);
int _change(info_t *);
int _allii(info_t *);
int _shell_his(info_t *);
void _handle_block(int);
ssize_t get_input(info_t *);
int ketay_mes(info_t *, char **, size_t *);
void _let_info(info_t *, int);
void _infoma(info_t *, char **);
int _initial_env(info_t *);
char *yaze(info_t *, const char *);
int _environ_list(info_t *);
int _rem_env(info_t *);
int _enviro(info_t *);
int nont(info_t *, char *, char *);
char **_botayge(info_t *);
int rem_env(info_t *, char *);
void _fou(info_t *);
#endif
