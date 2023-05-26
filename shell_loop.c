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
info->line_count++;
built_in_ret = builtins[i].func(info);
break;
}
return (built_in_ret);
}



