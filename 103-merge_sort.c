#include "sort.h"

/**
 * combine - combine left and right
 * @array: array
 * @s: start
 * @m: midpoint
 * @e: end
 */

void combine(int *array, int s, int m, int e)
{
	int i, j, k, *buff;

	buff = malloc(sizeof(int) * (e + 1));
	k = s;
	while (k <= e)
	{
		buff[k] = array[k];
		k = k + 1;
	}
	i = s;
	j = m + 1;
	k = s;
	while (i <= m && j <= e)
	{
		if (buff[i] <= buff[j])
		{
			array[k] = buff[i];
			i = i + 1;
		}
		else
		{
			array[k] = buff[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while (i <= m)
	{
		array[k] = buff[i];
		i = i + 1;
		k = k + 1;
	}
	while (j <= e)
	{
		array[k] = buff[j];
		j = j + 1;
		k = k + 1;
	}
	printf("[Done]: ");
	print_array(array + s, e - s), free(buff);
}

/**
 * mrg_sort_recursion - auxiliary/helper function
 * @a: array
 * @s: start
 * @e: end
 */

void mrg_sort_recursion(int a[], int s, int e)
{
	int m;

	/* Base case nover true */
	if (s >= e)
	{
		return;
	}

	/* find mid point value */
	m = (s + e) / 2;

	/* use recursion */
	mrg_sort_recursion(a, s, m);
	mrg_sort_recursion(a, m + 1, e);
	combine(a, s, m, e);
}

/**
 * merge_sort - merge sort alg
 * @array: array
 * @size: size
 */

void merge_sort(int *array, size_t size)
{
	mrg_sort_recursion(array, 0, size - 1);
}
