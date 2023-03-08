#include "sort.h"

/**
 * counting_sort - Counting sort
 * @array: Array to sort
 * @new_array: Copy of sort array
 * @size: Size of sort array
 * @mod: Current module
 * @div: Current division
 * Return: 0 if successful, otherwise 1
 */
int counting_sort(int *array, int *new_array, size_t size, int mod, int div)
{
	int buf[D_MAX] = {0}, i = 0, digit = 0;
	int count = 0;

	for (i = 0; i < (int)size; i++)
	{
		digit = (array[i] % mod) / div;
		if ((array[i] / div) == 0)
			count++;
		if (count == (int)size - 1)
			return (1);
		new_array[i] = array[i];
		buf[digit]++;
	}
	for (i = 1; i < D_MAX; i++)
		buf[i] += buf[i - 1];
	for (i = D_MAX - 1; i >= 0; i--)
	{
		digit = (new_array[i] % mod) / div;
		array[--buf[digit]] = new_array[i];
	}
	return (0);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * The Radix sort algorithm, implement the LSD radix sort algorithm
 * @array: Array to sort
 * @size: Length of the array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int mod = 10, div = 1;
	int *new_array = NULL;

	if (!array || size < 2)
		return;
	new_array = malloc(sizeof(int) * size);
	if (!new_array)
	{
		fprintf(stderr, "Can not malloc\n");
		return;
	}
	while (1)
	{
		if (counting_sort(array, new_array, size, mod, div))
			break;
		print_array(array, size);
		div *= 10;
		mod *= 10;
	}
	free(new_array);
}
