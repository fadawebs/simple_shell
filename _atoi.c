#include "shell.h"
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
            return (1);
    return (0);
}
/**
 * split -  uses this is_delim function to split the input string into an array of strings
 * @d:  delimiters to split the string on
 * @c: the input of the string to be split
 * Return: 0
 */
char **split(char *str, char *d)
{
    int i, j, k, m, numwords = 0;
    char **s;

    if (!str || !str[0])
        return (NULL);
    if (!d)
        d = " ";
    for (i = 0; str[i]; i++)
        if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
            numwords++;

    if (!numwords)
        return (NULL);

    s = malloc((numwords + 1) * sizeof(char *));
    if (!s)
        return (NULL);
    for (j = 0; j < numwords; j++)
    {
        while (is_delim(*str, d))
            str++;
        k = 0;
        while (!is_delim(str[k], d) && str[k])
            k++;
        s[j] = malloc((k + 1) * sizeof(char));
        if (!s[j])
        {
            for (k = 0; k < j; k++)
                free(s[k]);
            free(s);
            return (NULL);
        }
        for (m = 0; m < k; m++)
            s[j][m] = str[m];
        s[j][m] = '\0';
        str += k;
    }
    s[j] = NULL;
    return s;
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
