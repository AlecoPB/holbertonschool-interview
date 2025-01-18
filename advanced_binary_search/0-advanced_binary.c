#include "search_algos.h"

/**
 * print_sub_array - Prints a sub-array of integers
 *
 * @array: The array to be printed
 * @start: starting index
 * @end: ending index
 *
 * Return: nothing
 */
void print_sub_array(const int *array, size_t start, size_t end)
{
	size_t i = start;

	printf("Searching in array: ");
	while (array && i <= end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * recursive_binary - Recursive function to perform advanced binary search
 * @array: Pointer to the first element of the array
 * @left: Left boundary of the current subarray
 * @right: Right boundary of the current subarray
 * @value: The value to search for
 *
 * Return: Index of the leftmost occurrence of value, or -1 if not found
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
	if (left > right)
		return (-1);

	print_sub_array(array, left, right);

	size_t mid = left + (right - left) / 2;

	/* Check if mid is the leftmost occurence */
	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return (mid);

	/* Keep searching the left half */
	if (array[mid] >= value)
		return (recursive_binary(array, left, mid, value));

	/* Keep searching in the right half */
	return (recursive_binary(array, mid + 1, right, value));
}

/**
 * advanced_binary - Initiates the recursive binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_binary(array, 0, size - 1, value));
}