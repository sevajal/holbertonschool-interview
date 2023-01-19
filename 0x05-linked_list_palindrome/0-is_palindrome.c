#include "lists.h"


/**
 * listint_len - returns the number of elements in a linked listint_t list.
 * @h: Pointer to the listint_t head.
 * Return: the number of elements in a linked listint_t list.
 */

int listint_len(const listint_t *h)
{
	int nodes = 0;

	while (h != NULL)
	{
		h = h->next;
		nodes++;
	}
	return (nodes);
}


/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the linked list.
 * An empty list is considered a palindrome.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */

int is_palindrome(listint_t **head)
{
	int length = listint_len(*head);
	int numbers[length];
	int x, i = 0;
	listint_t *tmp = *head;

	while (tmp != NULL)
	{
		numbers[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}

	x = length - 1;
	i = 0;
	while (i <= length / 2)
		if (numbers[i] == numbers[x])
		{
			i++;
			x--;
		}
		else
			return (0);
	return (1);
}
