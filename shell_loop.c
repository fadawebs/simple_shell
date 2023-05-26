#include "shell.h"

/**
 * find_builtin - finds and executes a builtin command
 * @info: pointer to info struct
 * Return: exit status of the builtin command
 */

int find_builtin(info_t *info)
{
int i, built_in_ret = -1;

static const struct
{
const char *name;
int (*func)(info_t *);
} builtins[] = {
{"exit", _shellexit},
{"env", _shellenv},
{"help", _shellhelp},
{"history", _shellhistory},
{"setenv", _shellsetenv},
{"unsetenv", _shellunsetenv},
{"cd", _shellcd},
{"alias", _shellalias},
{NULL, NULL}};

for (i = 0; builtins[i].name != NULL; i++)
{
if (_strcmp(info->argv[0], builtins[i].name) == 0)
{
info->line_count++;
built_in_ret = builtins[i].func(info);
break;
}
}

return (built_in_ret);
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */

void fork_cmd(info_t *info)
{
pid_t child_pid = fork();

if (child_pid == -1)
{
perror("Error:");
return;
}
if (child_pid == 0)
{
int ret = execve(info->path, info->argv, get_environ(info));
free_info(info, 1);
if (ret == -1)
{
if (errno == EACCES)
{
exit(126);
}
else
{
exit(1);
}
}
}
else
{
wait(&info->status);
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
{
print_error(info, "Permission denied\n");
}
}
}
}

/**
 * hsh - main shell loop
 * @info: pointer to info struct
 * @av: array of strings
 * Return: exit status
 */
int hsh(info_t *info, char **av)
{
ssize_t r = 0;
int builtin_ret = 0;

do
{
clear_info(info);

if (interactive(info))
{
_puts("Beekaz$ ");
}

_eputchar(BUF_FLUSH);
r = get_input(info);

if (r != -1)
{
set_info(info, av);
builtin_ret = find_builtin(info);

if (builtin_ret == -1)
{
find_cmd(info);
}
}
else if (interactive(info))
{
_putchar('\n');
}

free_info(info, 0);
}
while (r != -1 && builtin_ret != -2);

write_history(info);
free_info(info, 1);

if (!interactive(info) && info->status)
{
exit(info->status);
}

if (builtin_ret == -2)
{
if (info->err_num == -1)
{
exit(info->status);
}

exit(info->err_num);
}

return (builtin_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(info_t *info)
{
char *path;
int arg_count = 0;

info->path = info->argv[0];

if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}

for (int i = 0; info->arg[i]; i++)
{
if (!is_delim(info->arg[i], " \t\n"))
{
arg_count++;
}
}

if (arg_count == 0)
{
return;
}
path = find_path(info, _getenv(info, "PATH="), info->argv[0]);

if (path != NULL)
{
info->path = path;
fork_cmd(info);
}
else if ((interactive(info) || _getenv(info, "PATH=") || info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
{
fork_cmd(info);
}
else if (*info->arg != '\n')
{
info->status = 127;
print_error(info, "not found\n");
}
}
