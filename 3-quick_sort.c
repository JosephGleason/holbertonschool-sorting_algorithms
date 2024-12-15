#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;
	int temp;

	/* Base case: if the partition size is more than 1 */
	if (low < high)
	{
		/* Set pivot to the last element of the partition */
		int pivot = array[high];
		int i = low - 1;
		int j;

		/* Loop through the array and move smaller elements to the left of pivot */
		for (j = low; j < high; j++)
		{
			if (array[j] < pivot)
			{
				i++;  /* Move the smaller element pointer */
				/* Swap array[i] and array[j] */
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}

		/* Place the pivot in its correct position */
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;

		/* Recursively sort the left and right partitions */
		quick_sort(array, i);  /* Sort the left partition */
		quick_sort(array + i + 2, high - i - 1);  /* Sort the right partition */
	}
}

