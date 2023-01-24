#include "sort.h"

/**
 * swap - creating a swap function
 * @array: array
 * @x: int 1
 * @y: int 2
 */

void swap(int *array, int x, int y)
{
	int temp;

	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

/**
 * locOfSmallest -  loc of small int in array
 * @a: array
 * @s: int
 * @e: ending point
 * Return: smallest
 */

int locOfSmallest(int a[], int s, int e)
{
	int i, j;

	i = s;
	j = i;

	while (i <= e)
	{
		if (a[i] < a[j])
		{
			j = i;
		}
		i = i + 1;
	}
	return (j);
}


/**
 * selection_sort - selection sort alg
 * @array: pointer to array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	unsigned long int i, j;

	i = 0;

	while (i < size - 1)
	{
		j = locOfSmallest(array, i, size - 1);
		swap(array, i, j);
		print_array(array, size);
		i++;
	}
}
