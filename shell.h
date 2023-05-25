
#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define HIST_FILE "history"
#define HIST_MAX 4096

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define USE_GETLINE 0
#define USE_STRTOK 0

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
int num;
char *str;
struct liststr *next;
} list_t;

/**
 * struct passinfo - Contains information about the shell
 * @arg: The argument
 * @argv: The argument vector
 * @path: The path
 * @argc: The argument count
 * @line_count: The line count
 * @err_num: The error number
 * @linecount_flag: The line count flag
 * @fname: The filename
 * @env: The environment list
 * @history: The history list
 * @alias: The alias list
 * @env_list: The environment list as an array
 * @env_changed: The environment change flag
 * @status: The status
 * @cmd_buf: The command buffer
 * @cmd_buf_type: The command buffer type
 * @readfd: The read file descriptor
 * @histcount: The history count
 */

typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **env_list;
int env_changed;
int status;
char **cmd_buf;
int cmd_buf_type;
int readfd;
int histcount;
} info_t;

#define INFO_INIT
{
arg = NULL,
argv = NULL,
path = NULL,
argc = 0,
line_count = 0,
err_num = 0,
linecount_flag = 0,
fname = NULL,
env = NULL,
history = NULL,
alias = NULL,
env_list = NULL,
env_changed = 0,
status = 0,
cmd_buf = NULL,
cmd_buf_type = 0,
readfd = 0,
histcount = 0
}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;

/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);


/*void find_cmd(info_t *);*/
void fork_cmd(info_t *);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *str);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_string.c */
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *starts_with(const char *, const char *);
char *_strcat(char *dest, const char *src);

/* toem_string1.c */
char *_strcpy(char *dest, const char *src);
void _puts(const char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **split(char *str, char *d);
/* char **strtow2(char *, char); */

/* toem_memory.c */
int bfree(void **);

/* toem_builtin1.c */
int _shellhistory(info_t *);
int _shellalias(info_t *);

/*toem_shell.c */
int _getline(info_t *, char **, size_t *);
ssize_t get_input(info_t *info);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
void sigintHandler(int sig_num);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);


/* toem_builtin.c */
int _shellhelp(info_t *info);
int _shellexit(info_t *info);
int _shellcd(info_t *info);

    /* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);


/* toem_history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);


/* toem_env_list.c */
char *_getenv(info_t *, const char *);
int _shellenv(info_t *);
int _shellsetenv(info_t *);
int _shellunsetenv(info_t *);
int populate_env_list(info_t *info);

/* toem_getenv.c */
char **get_env_list(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);

/* toem_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalphabetic(int);
int _atointeger(char *);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

void *memmove(void *dest, const void *src, size_t n);


#endif
