#include "shell.h"

/**
 * split - uses this is_delim function to split the input
 * string into an array of strings
 * @str: the input string
 * @d: the delimiter
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (!str || !str[0])
		/* Check if str is null or an empty string */
		return NULL;

	if (!d)  /* Check if d is null */
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
		while (str && is_delim(*str, d))
			/* Check if str is null */
			str++;

		k = 0;

		while (str && !is_delim(str[k], d) && str[k])
			/* Check if str is null */
			k++;

		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return NULL;
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[m];
		s[j][m] = '\0';
			if (str)
				str += k;
	}
	s[j] = NULL;
	return s;
}
