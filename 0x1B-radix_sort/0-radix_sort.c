#include "sort.h"

/**
 * counting_sort - Counting sort
 * @array: Array to sort
 * @new_array: Copy of sort array
 * @size: Size of sort array
 * @div: Current division
 * Return: 0 if successful, otherwise 1
 */
int counting_sort(int *array, int *new_array, size_t size, int div)
{
	int buf[D_MAX] = {0}, i = 0, digit = 0, count = 0;

	for (i = 0; i < (int)size; i++)
	{
		if ((array[i] / div) == 0)
			count++;
		if (count == (int)size - 1)
			return (1);
		digit = (array[i] / div) % D_MAX;
		buf[digit]++;
		new_array[i] = array[i];
	}
	for (i = 1; i < D_MAX; i++)
		buf[i] += buf[i - 1];
	for (i = (int)size - 1; i >= 0; i--)
	{
		digit = (new_array[i] / div) % D_MAX;
		array[--buf[digit]] = new_array[i];
	}
	print_array(array, size);
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
	int div = 1, *new_array = NULL, res = 0;

	if (!array || size < 2)
		return;
	new_array = malloc(sizeof(int) * size);
	if (!new_array)
	{
		fprintf(stderr, "Can not malloc\n");
		return;
	}
	for (div = 1; !res; div *= D_MAX)
		res = counting_sort(array, new_array, size, div);
	free(new_array);
}
