#include "sort.h"

/**
 * bubble_sort - a function to sort the array with bubble sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	int flag, temp;

	if (size >= 2)
	{
		for (i = 0; i < size - 1; i++)
		{
			flag = 0;
			for (j = 0; j < size - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					flag = 1;
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
				}
			}
			if (!flag)
				break;
		}
	}
}
