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
	listint_t *h, *tmp, *current;
	int num;

	if (!list || *list == NULL)
		return;
	
	len = listint_len(*list);
	if (len < 2)
		return;

	tmp = (*list)->next;

	while (tmp != NULL)
	{
		num = tmp->n;
		h = tmp;
		current = tmp;
		
		if (num < h->prev->n)
		{
			while (num < h->prev->n && h->next != NULL)
			{
				current = h->prev;
				h = h->next;
				print_list(*list);
			}
		}
		tmp = tmp->next;
	}
}
