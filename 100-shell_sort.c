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
 * shell_sort - shell sort alg
 * @array: array
 * @size: size
 */

void shell_sort(int *array, size_t size)
{
	unsigned long int g, i, j;

	if (array == NULL || size < 2)
		return;

	for (g = 1; g < (size / 3);)
		g = g * 3 + 1;

	for (; g >= 1; g /= 3)
	{
		for (i = g; i < size; i++)
		{
			j = i;
			while (j >= g && array[j - g] > array[j])
			{
				swp(array + j, array + (j - g));
				j -= g;
			}
		}
		print_array(array, size);
	}
}
