#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm.
 * @head: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **head)
{
	listint_t *cur, *prev, *next;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	cur = (*head)->next;

	while (cur != NULL)
	{
		prev = cur->prev;
		next = cur->next;

		while (prev != NULL && prev->n > cur->n)
		{
			prev->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = prev;

			cur->prev = prev->prev;
			cur->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = cur;
			else
				*head = cur;

			prev->prev = cur;
			print_list(*head);
			prev = cur->prev;
		}

		cur = next;
	}
}

