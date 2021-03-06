#ifndef __LISTS_H__
#define __LISTS_H__

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - singly linked list
 * @n: Integer
 * @next: Points to the next node
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);

listint_t *insert_node(listint_t **head, int number);

#endif
