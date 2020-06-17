#include <stdlib.h>
#include "palindrome.h"

/**
 * is_palindrome - Function that checks if an integer is palindrome
 * @n: number to check
 * Return: 1 if n is palindrome, otherwise 0
*/

int is_palindrome(unsigned long n)
{
	unsigned long reverse, copy, aux;

	reverse = 0;
	copy = n;
	aux = 0;

	while (n != 0)
	{
		aux = n % 10;
		reverse = reverse * 10 + aux;
		n /= 10;
	}

	if (copy == reverse)
		return (1);

	return (0);
}
