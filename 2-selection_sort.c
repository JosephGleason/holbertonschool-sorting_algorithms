#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_index, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
