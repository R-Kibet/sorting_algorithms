#include "sort.h"

/**
 * max - maximum value in an array
 * @array: array
 * @size: size
 *
 * Return: max value
 */
int max(int *array, int size)
{
	int mx, i;

	for (mx = array[0], i = 1; i < size; i++)
	{
		if (array[i] > mx)
			mx = array[i];
	}

	return (mx);
}

/**
 * counting_sort - counting sort alg
 * @array: array
 * @size: size
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, mx, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	mx = max(array, size);
	count = malloc(sizeof(int) * (mx + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (mx + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (mx + 1); i++)
		count[i] += count[i - 1];
	print_array(count, mx + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
