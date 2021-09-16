#include "sort.h"

/**
  * heap_sort - sort using heap sort algorithm
  * @arr: array to sort
  * @size: size of the array
  */
void heap_sort(int* arr, size_t size)
{
	int i, tmp;

	if (size <= 1)
		return;

	if (size == 2)
	{
		if (arr[0] >= arr[1])
		{
			tmp = arr[0];
			arr[0] = arr[1];
			arr[1] = tmp;
			print_array(arr, size);
		}
		return;
	}

	heap(arr, size, ((size - 2) / 2) - 1);

	for (i = size - 1; i > 0; i--)
	{
		tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		print_array(arr, size);

		if (i >= 1)
			move(arr, 0, i, size);
	}
}

/**
 * heap - shows array like a heap
 * @arr: array to process
 * @size: size of the array
 * @i: beginning of heap
 */
void heap(int* arr, size_t size, int i)
{
	int max = i;
	int l = 2 * i + 1, r = 2 * i + 2;
	int tmp;

	if (l >= (int)size || r >= (int)size)
		return;

	if (arr[l] > arr[max])
		max = l;

	if (arr[r] > arr[max])
		max = r;

	if (max != i)
	{
		tmp = arr[i];
		arr[i] = arr[max];
		arr[max] = tmp;
		print_array(arr, size);
	}

	if (max != i)
		heap(arr, size, ((size - 2) / 2) - 1);
	else if (i > 0)
		heap(arr, size, i - 1);
}

/**
 * move - prepares the heap
 * @arr: array to process
 * @start: starting node
 * @end: ending node
 * @size: size of the array
 */
void move(int* arr, int start, int end, size_t size)
{
	int max = start;
	int l = start * 2 + 1, r = start * 2 + 2;
	int tmp;

	if (r > end && l > end)
		return;

	if (l < end && arr[l] > arr[max])
		max = l;

	if (r < end && arr[r] > arr[max])
		max = r;

	if (max != start)
	{
		tmp = arr[start];
		arr[start] = arr[max];
		arr[max] = tmp;
		print_array(arr, size);
		move(arr, max, end, size);
	}
}