#include "search_algos.h"

/**
 * advanced_binary - searches for first occurence of given value
 * @array: array to search in
 * @size: size of array
 * @value: value to search for
 *
 * Return: index of found value, -1 on failure
 */
int advanced_binary(int* array, size_t size, int value)
{
	int mid = (size - 1) / 2;
	int res = 0;
	size_t i;

	if (array == NULL || size < 1)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);

		if (i != size - 1)
			printf(", ");
		else
			printf("\n");
	}

	if (array[mid] == value && mid == 0)
		return (mid);

	if (size == 1)
		return (-1);

	if (array[mid] >= value)
		return (advanced_binary(array, mid + 1, value));

	mid++;
	res = advanced_binary(&array[mid], size - mid, value);

	if (res == -1)
		return (-1);

	return (mid + res);
}
