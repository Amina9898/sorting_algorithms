#include "sort.h"

/**
 * lomuto_scheme - a function that sorts the elements of an array
 * according to the lomuto partitioning scheme
 * @arr: array to sort
 * @low: first index of the array
 * @high: last index of the array
 * Return - the index of the pivot after partitioning
 */

int lomuto_scheme(int *array, int low, int high)
{
	int pivot, i, j, tmp, tmp2;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

			print_array(array, high + 1);
		}
	}

	tmp2 = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp2;

	print_array(array, high + 1);

	return i + 1;
}

int main()
{
	int array[] = {22, 44, 6, 7, 9, 3, 55, 22, 13, 11};

	lomuto_scheme(array, 0, 9);
}
/**
 * quick_sort - function that sorts an array of integer
 * in ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 *

void quick_sort(int *array, size_t size)
{

}
*/

