#include "lists.h"

/**
 * check_cycle - Function that checks if a singly linked list has a cycle in it
 * @list: the list to check
 * Return: 0 if there is no cycle, 1 if there is a cycle
*/

int check_cycle(listint_t *list)
{
	listint_t *first, *second;

	if (!list)
		return (0);

	if (!list->next)
		return (0);

	first = list;
	second = list;

	while (first && second && second->next)
	{
		first = first->next;
		second = second->next->next;
		if (first == second)
			return (1);
	}
	return (0);
}
