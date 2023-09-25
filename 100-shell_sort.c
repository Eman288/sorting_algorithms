#include "sort.h"
/**
 * shell_sort - sorts the array with the shell sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gab, j, k;

	int temp;
	gab = 1;
	for (; gab < size / 3;)
		gab *= 3 + 1;
	for (; gab >= 1;)
	{
		for (j = gab; j < size; j++)
		{
			k = j;
			while (k >= gab && array[k] < array[k - gab])
			{
				temp = array[k];
				array[k] = array[k - gab];
				array[k - gab] = temp;
				k -= gab;
			}
		}
		gab /= 3;
		print_array(array, size);
	}
}
