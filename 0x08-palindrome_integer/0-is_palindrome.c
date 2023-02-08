#include "palindrome.h"
#include <stdio.h>
#include <string.h>

/**
 * is_palindrome - checks if a given unsigned integer is a palindrome.
 * @n: unsigned long int.
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	char str[30];
	int len = 0, i = 0, j = 0;

	sprintf(str, "%ld", n);
	len = strlen(str);
	j = len - 1;
	for (i = 0; i < j; i++)
	{
		for (; j > i; j--)
		{
			if (str[i] != str[j])
				return (0);
		}
	}
	return (1);
}
