#ifndef LIST_H
#define LIST_H

/**
 * struct list - Represents a linked list node.
 * @str: Pointer to a string data.
 * @next: Pointer to the next node in the list.
 * @num: Numeric data associated with the node.
 */
typedef struct list
{
    char *str;
    struct list *next;
    int num;
} list_t;

#endif /* LIST_H */
