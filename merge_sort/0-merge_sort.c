#include <stdio.h>
#include <stdlib.h>
#include "print_array.h"

/**
 * merge - Merges two subarrays into a single sorted subarray.
 * @array: The original array to sort.
 * @temp: Temporary array for merging.
 * @left: Starting index of the left subarray.
 * @mid: Ending index of the left subarray.
 * @right: Ending index of the right subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = left;

    /* Merge the two subarrays into temp */
    while (i < mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    /* Copy remaining elements from the left subarray */
    while (i < mid)
        temp[k++] = array[i++];

    /* Copy remaining elements from the right subarray */
    while (j <= right)
        temp[k++] = array[j++];

    /* Copy merged data back to the original array */
    for (i = left; i <= right; i++)
        array[i] = temp[i];

    /* Print the current array */
    printf("Merging...\n");
    print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursively sorts an array using merge sort.
 * @array: The original array to sort.
 * @temp: Temporary array for merging.
 * @left: Starting index of the subarray.
 * @right: Ending index of the subarray.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    if (left >= right)
        return;

    /* Split the array into two halves */
    size_t mid = left + (right - left) / 2;

    /* Sort the left half */
    merge_sort_recursive(array, temp, left, mid);

    /* Sort the right half */
    merge_sort_recursive(array, temp, mid + 1, right);

    /* Merge the two halves */
    merge(array, temp, left, mid + 1, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    /* Allocate temporary array for merging */
    int *temp = malloc(size * sizeof(int));
    if (!temp)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return;
    }

    /* Perform recursive merge sort */
    merge_sort_recursive(array, temp, 0, size - 1);

    /* Free the temporary array */
    free(temp);
}
