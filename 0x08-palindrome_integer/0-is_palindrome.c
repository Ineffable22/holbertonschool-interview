#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given unsigned integer
 * is a palindrome.
 * @n: Is the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long start = 0, end = 0, digit = 0, mul = 0;
	unsigned long i = 0, j = 0, num = n, x = 0;

	for (digit = 0; num > 0; digit++)
		num /= 10;

	for (j = 0, i = digit; j < digit / 2; j++)
	{
		for (x = 1, mul = 1; x < i; x++)
			mul *= 10;
		start = n / mul;
		end = n % 10;
		if (start != end)
			return (0);
		n = (n % mul) / 10;
		i -= 2;
	}
	return (1);
}
