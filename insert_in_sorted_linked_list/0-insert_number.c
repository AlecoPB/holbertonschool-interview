#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Finds the maximum number in the array
 * @array: The array to check
 * @size: The size of the array
 * Return: The maximum integer in the array
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort_by_digit - Sorts the array by the current digit
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The current digit position to sort by
 */
void counting_sort_by_digit(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (!output)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size; i > 0; i--)
    {
        int digit = (array[i - 1] / exp) % 10;
        output[count[digit] - 1] = array[i - 1];
        count[digit]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using LSD radix sort
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (size < 2 || !array)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_by_digit(array, size, exp);
        print_array(array, size);
    }
}
