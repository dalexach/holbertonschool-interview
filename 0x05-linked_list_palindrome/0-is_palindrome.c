#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse - Function to reverse the list
 * @head: head of the list
 * Return: Nothing (void)
 */

void reverse(listint_t **head)
{
	listint_t *curr = *head;
	listint_t *p = NULL;
	listint_t *n = NULL;

	while (curr)
	{
		n = curr->next;
		curr->next = p;
		p = curr;
		curr = n;
	}
	*head = p;
}

/**
 * keepMiddle - Function to split the list
 * @head: head of the list
 * Return: the middle of the list
 */

listint_t *keepMiddle(listint_t **head)
{
	listint_t *r = *head;
	listint_t *l = *head;

	while (l && l->next)
	{
		r = r->next;
		l = l->next->next;
	}
	return (r);
}

/**
 * is_palindrome - Function that checks if a singly linked list is a palindrome
 * @head: head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *mid;
	int f = 0;

	if (*head == NULL)
		return (1);

	mid = keepMiddle(head);

	/** reverse the list */
	reverse(&mid);

	/** compare the lists */
	while (mid)
	{
		if (mid->n != (*head)->n)
			return (0);
		*head = (*head)->next;
		mid = mid->next;
		f = 1;
	}
	if (f == 1)
		return (1);
	return (0);
}
