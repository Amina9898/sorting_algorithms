#include "sort.h"

/**
 * lomuto_scheme - a function that sorts the elements of an array
 * according to the lomuto partitioning scheme
 * @array: array to sort
 * @low: first index of the array
 * @high: last index of the array
 * @size: size of the array
 */

void lomuto_scheme(int *array, int low, int high, int size)
{
	int pivot, i, j, tmp;

	if (low < high)
	{
		pivot = high;
		i = low;

		for (j = low; j < high; j++)
		{
			if (array[j] < array[pivot])
			{
				if (j != i)
				{
					tmp = array[j];
					array[j] = array[i];
					array[i] = tmp;
					print_array(array, size);
				}
				i++;
			}
		}
		if (i != pivot && array[i] != array[pivot])
		{
			tmp = array[i];
			array[i] = array[pivot];
			array[pivot] = tmp;
			print_array(array, size);
		}
		lomuto_scheme(array, low, i - 1, size);
		lomuto_scheme(array, i + 1, high, size);
	}

}

/**
 * quick_sort - function that sorts an array of integer
 * in ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	lomuto_scheme(array, 0, size - 1, size);
}

