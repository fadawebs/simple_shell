#include "shell.h"

/**
 * _realloc - reallocates a space of memory
 * @ptr: pointer to previous malloc'ated space
 * @old_size: byte size of previous space
 * @new_size: byte size of new space
 *
 * Return: pointer to the old space.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr;

if (new_size == 0)
{
free(ptr);
return (NULL);
}

if (!ptr)
{
return (malloc(new_size));
}

if (new_size == old_size)
{
return (ptr);
}

new_ptr = malloc(new_size);
if (!new_ptr)
{
return (NULL);
}

memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
free(ptr);

return (new_ptr);
}

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 *
 * Return: void
 */
void ffree(char **pp)
{
char **a = pp;

if (!pp)
return;

free(*pp++);

free(a);
}
