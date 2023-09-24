#include "sort.h"
/**
 * insertion_sort_list - a function to sort the list with the inseration sort
 * list -  the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *cur, *p, *g;

	temp = *list;
	while (temp != NULL)
	{
		cur = temp;
		while (cur->prev != NULL && cur->n < cur->prev->n)
		{
			g = cur;
			p = g->prev;
			p->prev->next = g;
			g->prev = p->prev;
			p->prev = g;
			p->next = g->next;
			g->next = p;
			print_list(*list);
		}
		temp = temp->next;
	}
}
