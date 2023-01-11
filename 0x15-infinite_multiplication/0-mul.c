#include "holberton.h"

/**
 * printer - Print a string
 * @str: string to print
 * @len: size of string
 *
 * Return: Nothing
 */
void printer(char *str, int len)
{
	for (; *(str + 1) != 0 && *(str + 1) == '0'; str++, len--)
	{}

	for (; len; len--, str++)
		if (*str)
			_putchar(*str);
	_putchar(0xA);
}

/**
 * is_digit - Identify if a string is a number
 * @str: String to identify
 *
 * Return: 1 is digit, otherwise 0 on failure
 */
char is_digit(char *str)
{
	if (*str && (*str < 48 || *str > 57))
		return (0);
	return (*str ? is_digit(str + 1) : 1);
}

/**
 * _strlen - Calculate the size of the string
 * @str: String to evaluate
 *
 * Return: String lenght
 */
int _strlen(char *str)
{
	return (*str ? _strlen(str + 1) + 1 : 0);
}

/**
 * multiplication - Create the multiplications of the strings
 * @num1: Number one
 * @num2: Number two
 *
 * Return: 1 if successful or 0 if failed
 */
int multiplication(char *num1, char *num2)
{
	int carry = 0, len1 = 0, len2 = 0, len = 0;
	char *number = NULL;

	len1 = _strlen(num1) - 1;
	len2 = _strlen(num2) - 1;
	len = len1 + len2 + 2;
	number = calloc(sizeof(char), (len + 1));
	if (number == NULL)
	{
		printer("Can not malloc", 14);
		return (0);
	}

	for (; num1[len1]; len1--)
	{
		for (carry = 0, len2 = _strlen(num2) - 1; num2[len2]; len2--)
		{
			carry += ((num2[len2] - 48) * (num1[len1] - 48));
			carry += number[(len1 + len2) + 1] ?
			number[(len1 + len2) + 1] - 48 : number[(len1 + len2) + 1];
			number[(len1 + len2) + 1] = (carry % 10) + 48;
			carry /= 10;
		}
		if (carry != 0)
			number[(len1 + len2) + 1] += (carry + 48);
	}
	printer(number, len);
	free(number);
	return (1);
}

/**
 * main - Multiplies two positive numbers
 * @argc: Number of arguments
 * @argv: Pointer to arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	(void) argv;
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2])
	|| !multiplication(argv[1], argv[2]))
	{
		printer("Error", 5);
		exit(98);
	}
	return (0);
}
