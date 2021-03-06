#include "lists.h"

/**
 * insert_node - Insert node by number value
 *
 * @head: Head of the list
 * @number: Number of new nodes to insert
 *
 * Return: The address of the new node, or NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if ((*head == NULL) || (*head)->n >= new->n)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL && temp->next->n < new->n)
			temp = temp->next;
		new->next = temp->next;
		temp->next = new;
	}
	return (new);
}
