#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort.
 * @head: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **head)
{
	listint_t *cur, *prev, *next;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	cur = (*head)->next;
	while (cur != NULL)
	{
		next = cur->next;
		while (cur->prev != NULL && cur->n < cur->prev->n)
		{
			prev = cur->prev;

			prev->next = cur->next;
			if (cur->next)
				cur->next->prev = prev;

			cur->prev = prev->prev;
			cur->next = prev;

			if (prev->prev)
				prev->prev->next = cur;
			else
				*head = cur;

			prev->prev = cur;

			print_list(*head);
		}
		cur = next;
	}
}
