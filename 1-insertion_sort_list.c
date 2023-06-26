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
	listint_t *h, *tmp, *p;

	if (!list || *list == NULL)
		return;
	
	len = listint_len(*list);
	if (len < 2)
		return;

	tmp = (*list)->next;

	while (tmp != NULL)
	{
		h = (*list)->next;
		while (h->next != NULL)
		{
			
			if (h->n < h->prev->n)
			{
				if(h->prev->prev != NULL)
				{
					p = h->prev->prev;
					h->next->prev = h->prev;
					h->prev->prev->next = h;
					h->prev->next = h->next;
					h->prev->prev = h;
					h->next = h->prev;
					h->prev = p;
					print_list(*list);
				}
				if (h->prev->prev == NULL)
				{
					h->prev->next = h->next;
					h->prev->prev = h;
					h->next->prev = h->prev;
					h->next = h->prev;
					h->prev = NULL;
					(*list) = h;
				}
				break;
			}
			h = h->next;
		}
		tmp = tmp->next;
	}
}
