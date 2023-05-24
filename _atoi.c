#include "shell.h"
#include <stdio.h>

/**
 * interactive - returns true if the shell is currently in interactive mode
 * @info: structure address
 *
 * Return: 1 if in interactive mode, else 0 otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *_atointeger - converts a string to an integer
 *@s: the string yet to be converted
 *Return: 0 if no numbers is in string, converted number otherwise
 */

int _atointeger(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the character to check
 * @d: for the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delim(char c, char *d)
{
	while (*d)

		if (c == *d++)
		{
			return (1);
		}
	return (0);
}

/**
 *_isalphabetic - checks for alphabetic character
 *@c: The character set to input
 *Return: 1 if c is alphabetic, else 0 otherwise
 */

int _isalphabetic(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
