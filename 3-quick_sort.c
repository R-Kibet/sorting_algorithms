#include "sort.h"

/**
 * swp - swaping  elements
 * @x: int
 * @y: int
 */

void swp(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - partition the array around pivot
 * @array: pointer to array
 * @low: lowest int
 * @high: highest int
 * @size: size
 * Return: value
 */

int partition(int *array, int low, int high, size_t size)
{
	int pvalue, i, j;

	pvalue = array[high];

	i = low;

	for (j = low ; j < high ; j++)
	{
		if (array[j] <= pvalue)
		{
			swp(&array[i], &array[j]);

			if (i != j)
				print_array(array, size);

			i++;
		}
	}
	swp(&array[i], &array[high]);
	if (i != j)
		print_array(array, size);
	return (i);
}

/**
 * quick_sort_recursion - recursion for alg
 * @array: pointer to array
 * @low: lowest int
 * @high: highest in
 * @size: size
 */

void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot - 1, size);
		quick_sort_recursion(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - quicksort alg
 * @array: pointer to array
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}
