#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - Linear search in a skip list
 * @list: pointer to the head of the skip list to search in.
 * @value: the value to search for.
 * Return: pointer on the first node where value is located or Null.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmpList;

	if (!list)
		return (NULL);
	tmpList = list;
	while (tmpList->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			  tmpList->express->index, tmpList->express->n);
		if (tmpList->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				  tmpList->index, tmpList->express->index);
			break;
		}
		tmpList = tmpList->express;
	}
	if (!tmpList->express)
	{
		list = tmpList;
		while (list->next)
			list = list->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			  tmpList->index, list->index);
	}
	list = tmpList;
	while (list != tmpList->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			  list->index, list->n);
		if (list->n == value)
			break;
		list = list->next;
	}
	if (list != tmpList->express)
		return (list);
	return (NULL);
}
