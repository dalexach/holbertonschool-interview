#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - function that insert a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: number to insert
 * Return: address of the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *temp;

	if (head == NULL)
		return (NULL);

	temp = *head;
	new = malloc(sizeof(listint_t));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->n = number;

	if (*head == NULL)
		new->next = NULL;
	else
	{
		if (number < temp->n)
		{
			new->next = temp;
			*head = new;
			return (*head);
		}
		else
		{
			while(temp->next != NULL)
			{
				if (temp->n < number && temp->next->n < number)
				{
					temp =  temp->next;
				}
				else
				{
					new->next = temp->next;
					temp->next = new;
					break;
				}
			}
			if (temp->next == NULL)
			{
				new->next = temp->next;
				temp->next = new;
			}
		}
	}

	return (new);
}
