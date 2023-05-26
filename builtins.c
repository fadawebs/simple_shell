#include "shell.h"

/**
 * _shellhelp - updates on how to use the shell
 * @info: Structure containing potential arguments
 *  Return: Always 0
 */
int _shellhelp(info_t *info)
{
	char **arg_array = info->argv;

	_puts("Help functions OK. Function not available \n");

	if (*arg_array != NULL)
	{
		_puts(*arg_array);
	}
	return (0);
}

/**
 * _shellcd - changes the current directory
 * @info: Used to maintain constant function prototype
 *  Return: Always 0
 */
int _shellcd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure alert here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "DIR=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		char *oldpwd = _getenv(info, "OLDPWD=");

		if (!oldpwd)
		{
			_puts(s), _putchar('\n');
			return (1);
		}
		_puts(oldpwd), _putchar('\n');
		chdir_ret = chdir(oldpwd);
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd into ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _shellexit - exit the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exit with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _shellexit(info_t *info)

{
int exitcheck = 0;
if (info->argv[1])
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Unidentified number: ");
_eputs(info->argv[1]);

_eputchar('\n');

return (1);

}
info->err_num = exitcheck;
return (-2);
}
info->err_num = -1;
return (-2);
}
