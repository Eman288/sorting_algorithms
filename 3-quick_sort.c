#include "sort.h"
/**
 * parti - get the partitial
 * @array: the array
 * @size: the size of the array
 * @l: the low index
 * @h: the high index
 * Return: the partitial index
*/
int parti(int *array, size_t size, int l, int h)
{
	int pivot, i, j, temp;

	pivot = array[l];
	i = l;
	j = h;
	while (i < j)
	{
		do {
			i++;
		} while (array[i] <= pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[j];
	array[j] = array[l];
	array[l] = temp;
	return (j);
}
/**
 * quicksort - the quick sort function
 * @array: the array
 * @size: the size of the array
 * @l: the low index
 * @h: the high index
*/
void quicksort(int *array, size_t size, int l, int h)
{
	int j;

	if (h - l > 0)
	{
		j = parti(array, size, l, h);
		quicksort(array, size, l, j);
		quicksort(array, size, j + 1, h);
	}
}
/**
 * quick_sort - the main function
 * @array: the array
 * @size: the size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, size, 0, size);
}
