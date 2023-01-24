#include "sort.h"

/**
 * swap_ahead - Swap a node ahead
 * @list: pointer to the head
 * @tail: pointer to the tail
 * @swp: pointer to swap node
 */
void swap_ahead(listint_t **list, listint_t **tail, listint_t **swp)
{
	listint_t *tmp = (*swp)->next;

	if ((*swp)->prev != NULL)
		(*swp)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*swp)->prev;
	(*swp)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *swp;
	else
		*tail = *swp;
	(*swp)->prev = tmp;
	tmp->next = *swp;
	*swp = tmp;
}

/**
 * swap_behind - Swap a node form behind
 * @list: pointer to head
 * @tail: pointer to tail
 * @swp: pointer to the current swapping node
 */

void swap_behind(listint_t **list, listint_t **tail, listint_t **swp)
{
	listint_t *tmp = (*swp)->prev;

	if ((*swp)->next != NULL)
		(*swp)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*swp)->next;
	(*swp)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *swp;
	else
		*list = *swp;
	(*swp)->next = tmp;
	tmp->prev = *swp;
	*swp = tmp;
}


/**
 * cocktail_sort_list - cock tail alg
 * @list: list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *swp;
	bool shkn = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shkn == false)
	{
		shkn = true;
		for (swp = *list; swp != tail; swp = swp->next)
		{
			if (swp->n > swp->next->n)
			{
				swap_ahead(list, &tail, &swp);
				print_list((const listint_t *)*list);
				shkn = false;
			}
		}
		for (swp = swp->prev; swp != *list;
				swp = swp->prev)
		{
			if (swp->n < swp->prev->n)
			{
				swap_behind(list, &tail, &swp);
				print_list((const listint_t *)*list);
				shkn = false;
			}
		}
	}
}
