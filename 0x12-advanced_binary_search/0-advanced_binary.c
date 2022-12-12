#include "search_algos.h"

/**
 * print_array - Print array
 * @array: Is a pointer to the first element of the array to search
 * @start: Index to start
 * @end: Index to end
 *
 * Return: Nothing
 */
void print_array(int *array, size_t start, size_t end)
{
	printf("Searching in array: ");
	for (; start <= end; start++)
	{
		printf("%d", array[start]);
		if (start != end)
		{
			putchar(0x2C);
			putchar(0x20);
		}
	}
	putchar(0xA);
}



/**
 * binary_search - Searches for a value in a sorted array of integers.
 * @array: Is a pointer to the first element of the array to search
 * @start: Index to start
 * @end: Index to end
 * @value: Is the value to search
 *
 * Return: The index where value is located and If value is not present
 * in array or if array is NULL, your function must return -1
 */
int binary_search(int *array, size_t start, size_t end, int value)
{
	size_t mid = (end + start) / 2;

	if (start < end)
	{
		print_array(array, start, end);
		if (array[mid] == value && start + 1 == end)
			return (mid);
		else if (array[mid] < value)
			return (binary_search(array, mid + 1, end, value));
		else if (array[mid] >= value)
			return (binary_search(array, start, mid, value));
	}
	print_array(array, start, end);
	if (value == array[start])
		return (start);
	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Is a pointer to the first element of the array to search
 * @size: Is the number of elements in array
 * @value: Is the value to search
 *
 * Return: The index where value is located and If value is not present
 * in array or if array is NULL, your function must return -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size <= 0)
		return (-1);
	return (binary_search(array, 0, size - 1, value));
}
