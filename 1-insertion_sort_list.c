#include "sort.h"

/**
  * listint_len - function to return length of d linked list
  * @h: header of the doubly linked list
  * Return: will return length of the list
  */

size_t listint_len(listint_t *h)
{
	size_t length = 0;
	const listint_t *tmp = h;

	while (tmp != NULL)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}

/**
  * insertion_sort_list - function to insertion sort double linked list
  * @list: double linked list to be sorted
  */

void insertion_sort_list(listint_t **list)
{
	size_t len;
	listint_t *h, *tmp;

	if (!list || *list == NULL)
		return;

	len = listint_len(*list);
	if (len < 2)
		return;

	tmp = (*list);

	while (tmp)
	{
		while (tmp->next && tmp->n > tmp->next->n)
		{
			h = tmp->next;
			tmp->next = h->next;
			h->prev = tmp->prev;

			if (tmp->prev)
				tmp->prev->next = h;
			if (h->next)
				h->next->prev = tmp;
			h->next = tmp;
			tmp->prev = h;

			if (h->prev)
				tmp = h->prev;
			else
				*list = h;
			print_list(*list);
		}
		tmp = tmp->next;
	}
}
