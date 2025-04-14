#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble Sort algorithm.
 *
 * @array: Pointer to the array of integers to sort
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int i, temp, swap;

	if (array == NULL || size < 2)
		return;

	swap = 1;
	while (swap != 0)
	{
		swap = 0;
		for (i = 0; i < (int)size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
