#include "sort.h"

/**
 * swap - Swap values
 * @a: First pointer
 * @b: Second pointer
 * @array: An unsorted array
 * @size: Array size
 *
 * Return: Nothing
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
 * heapify - build a heap tree
 * @array: An unsorted array
 * @n: Heap size
 * @i: index of node
 * @size: Array size
 *
 * Return: Nothing
 */
void heapify(int *array, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest], array, size);
		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: An unordered array
 * @size: Array size
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i = 0;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heapify(array, i, 0, size);
	}
}
