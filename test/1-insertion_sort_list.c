#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
*                       in ascending order using the Insertion sort algorithm
*
* @list: A double pointer to the head of the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current;
	current = (*list)->next;
	listint_t *prev;

	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			if (current->next != NULL)
				current->next->prev = prev;
			prev->next = current->next;
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			prev = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
