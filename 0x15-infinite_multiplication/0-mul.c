#include "holberton.h"

/**
 * _isdigit - check if a string contain only digits.
 * @str: pointer to string
 * Return: 1 if only digits, 0 if not.
 */
int _isdigit(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - function that returns the length of a string
 * @str: pointer to string
 * Return: string length, int.
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

/**
 * _mul - function that multiply 2 digit strings
 * @str1: 1st string to multiply
 * @str2: 2nd string to multiply
 * Return: result of the multiplication
 */

char *_mul(char *str1, char *str2)
{
	char *result;
	int x, y, z, total_length, len_s1, len_s2;

	len_s1 = _strlen(str1), len_s2 = _strlen(str2);
	total_length = len_s1 + len_s2;

	result = malloc(total_length);
	if (!result)
		printf("Error\n"), exit(98);

	for (len_s1--; len_s1 >= 0; len_s1--)
	{
		x = str1[len_s1] - '0';
		z = 0;
		for (len_s2 = _strlen(str2) - 1; len_s2 >= 0; len_s2--)
		{
			y = str2[len_s2] - '0';
			z += result[len_s1 + len_s2 + 1] + (x * y);
			result[len_s1 + len_s2 + 1] = z % 10;
			z /= 10;
		}
		if (z)
			result[len_s1 + len_s2 + 1] += z;
	}
	return (result);
}

/**
 * main - entry to main
 * @argc: number of arguments
 * @argv: arguments
 * Return: multiplied numbers
 */
int main(int argc, char *argv[])
{
	int i, x = 0, length = 0;
	char *result;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
		puts("Error"), exit(98);

	length = _strlen(argv[1]) + _strlen(argv[2]);
	result = _mul(argv[1], argv[2]);

	for (i = 0; i < length; i++)
	{
		if (result[i])
			x = 1;
		if (x)
			_putchar(result[i] + '0');
	}
	if (x == 0)
		_putchar('0');
	puts("");
	free(result);
	return (0);
}
