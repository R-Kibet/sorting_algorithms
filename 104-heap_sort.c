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
 * max_heapify -  binary tree -> binary heap.
 * @array: array
 * @size: size
 * @base: base index
 * @root: root node
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swp(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - heap sort alg
 * @array: array
 * @size: size
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swp(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
