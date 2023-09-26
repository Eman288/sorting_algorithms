#include "sort.h"
/**
 * swap_nodes_next -  a function to swap two nodes in the forward dirrction
 * @head: the header of the list
 * @a: the first node
 * @b: the second node
 */
void swap_nodes_next(listint_t **head, listint_t **a, listint_t *b)
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
 * swap_nodes_prev -  a function to swap two nodes in the back dirrction
 * @list: the header of the list
 * @a: the first node
 * @b: the second node
 */
void swap_nodes_prev(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *tmp;

	tmp = (*b)->prev;
	if ((*b)->next != NULL)
		(*b)->next->prev = tmp;
	else
		*a = tmp;
	tmp->next = (*b)->next;
	(*b)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *b;
	else
		*list = *b;
	(*b)->next = tmp;
	tmp->prev = *b;
	*b = tmp;
}
/**
 * cocktail_sort_list - a function that sort the list with the cocktail sort
 * @list: the list
 */
void cocktail_sort_list(listint_t **list)
{
	int i, n = 0;

	listint_t *s, *l, *move, *temp = *list;

	s = temp;
	if (list == NULL || temp == NULL || temp->next == NULL)
		return;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			l = temp;
		temp = temp->next;
		n++;
	}
	for (i = 0; i < n ; i++)
	{
		move = s;
		for (; move->next; )
		{
			if (move->n > move->next->n)
			{
				swap_nodes_next(list, &move, move->next);
				print_list(*list);
			}
			if (move->next != NULL)
				move = move->next;
		}
		move = l;
		for (; move->prev; )
		{
			if (move->n < move->prev->n)
			{
				swap_nodes_prev(list, &move->prev, &move);
				print_list(*list);
			}
			if (move->prev != NULL)
				move = move->prev;
		}
	}
}
