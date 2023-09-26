#include "sort.h"
/**
 * get_prefix_arr - get the prefix array
 * @array: the main array
 * @size: the size of the main array
 * @arr: the prefix array
 * @max: the size of the prefix array
 * Return: the prefix array
 */
int *get_prefix_arr(int *array, size_t size, int *arr, int max)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		arr[array[i]]++;
	}
	for (i = 1; max != 0; i++)
	{
		arr[i] += arr[i - 1];
		max--;
	}
	return (arr);
}
/**
 * counting_sort - a function to sort with the counting algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *arr, *out, max;

	size_t i;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	arr = malloc(sizeof(int) * max + 1);
	if (!arr)
		return;
	arr = get_prefix_arr(array, size, arr, max);
	print_array(arr, max + 1);
	out = malloc(sizeof(int) * size);
	if (!out)
		return;
	for (i = size - 1; array[i]; i--)
	{
		out[arr[array[i]] - 1] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = out[i];
	free(out);
	free(arr);
}
