#include "sort.h"

/**
 * swap - swaping  elements
 * @array: aray
 * @x: int
 * @y: int
 */

void swap(int *array, int x, int y)
{
	int temp;

	y = x + 1;

	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}


/**
 * bubble - sort from last to fisrst
 * @array: array
 * @size: size
 */

void bubble(int *array, size_t size)
{
	int i, j;

	/* last element */
	i = size - 1;

	for (j = 0; j < i ; j++)
	{
		if (array[j] > array[j + 1])
		{
			swap(array, j, j + 1);
			print_array(array, size);
		}
	}
}


/**
 * bubble_sort - bubble sort alg
 * @array: pointer to array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned long int i;

	i = 0;

	while (i < size - 1)
	{
		bubble(array, size);
		i++;
	}
}
