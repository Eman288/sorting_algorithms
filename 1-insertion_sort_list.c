#include "sort.h"
/**
 * swab_nodes -  a function to swap two nodes
 * @head: the header of the list
 * @a: the first node
 * @b: the second node
 */
void swap_nodes(listint_t **head, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;
	if (b->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev != NULL)
		(*a)->prev->next = b;
	else
		*head = b;
	(*a)->prev = b;
	*a = b->prev;
}
/**
 * insertion_sort_list - a function to sort the list with the inseration sort
 *@list:  the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *g, *p, *cur, *temp;

	temp = *list;
	if (list == NULL || temp == NULL || temp->next == NULL)
		return;
	for (g = temp->next; g != NULL; g = cur)
	{
		cur = g->next;
		p = g->prev;
		while (p != NULL && g->n < p->n)
		{
			swap_nodes(list, &p, g);
			print_list(*list);
		}
	}
}
