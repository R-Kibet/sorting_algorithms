#include "sort.h"

/**
 * selection_sort - selection sort alg
 * @array: pointer to array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	unsigned long int i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		unsigned int x = i;
		int aux = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < aux)
				aux = array[j], x = j;
		}
		if (x != i)
		{
			array[x] = array[i];
			array[i] = aux;
			print_array(array, size);
		}
	}
}
