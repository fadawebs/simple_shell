#include "shell.h"

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;

if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused)) int sig_num)
{
_puts("\n");
_puts("Beekaz$ ");
_putchar(BUF_FLUSH);
}

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t r = 0;
if (!*len)
{
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);

size_t len_p = 0;
#if USE_GETLINE
r = getline(buf, &len_p, stdin);
#else
r = _getline(info, buf, &len_p);
#endif

if (r > 0)
{
if ((*buf)[r - 1] == '\n')
{
(*buf)[r - 1] = '\0';
r--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
if (_strchr(*buf, ';'))
{
*len = r;
info->cmd_buf = buf;
}
else
{
*len = r + 1;
}
}
}
return (r);
}

/**
 * get_input - gets a line of input from STDIN
 * @info: parameter struct
 *
 * Return: bytes read
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t i, len;
ssize_t r = read_buf(info, buf + len, &(READ_BUF_SIZE - len));

if (r < 1)
return (-1);

len += r;
char *pos = memchr(buf + i, '\n', len - i);
size_t new_len = pos ? (size_t)(pos - buf) + 1 : len;
char *new_ptr = realloc(*ptr, new_len);

if (!new_ptr)
return (free(*ptr), *ptr = NULL, -1);

*ptr = new_ptr;
memcpy(new_ptr, buf + i, new_len - i);
*length = new_len - i;

if (new_len == len)
i = len = 0;
else
i = (size_t)(pos - buf) + 1;

return ((ssize_t)(*length));
}

