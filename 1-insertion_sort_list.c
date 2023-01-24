#include "sort.h"

/**
 * swap_one - swap doubl list
 * @list: list
 * @i: left
 * @n: right
 * Return: value
 */

listint_t *swap_one(listint_t **list, listint_t *i, listint_t *n)
{
	if (i->prev)
		(i->prev)->next = n;
	else
		*list = n, n->prev = NULL;
	if ((n->next))
		(n->next)->prev = i;

	n->prev = i->prev;
	i->prev = n;
	i->next = n->next;
	n->next = i;

	return (i);
}


/**
 * insertion_sort_list - insert sort alg
 * @list: pointer to list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *act, *prev, *back;

	if (!list || !(*list) || !(*list)->next)
		return;

	act = (*list)->next;

	while (act)
	{
		prev = act->prev;
		back = act;

		while (back->prev && back->n < prev->n)
		{
			act = swap_one(list, prev, back);
			print_list(*list);
			if (!back->prev)
				break;
			prev = back->prev;
		}
		act = act->next;
		prev = prev->next;
	}
}
