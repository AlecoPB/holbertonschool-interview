#include <stdio.h>

void print_array(const int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t end);
void heap_sort(int *array, size_t size);

/**
 * print_array - Prints an array of integers.
 * @array: The array to print.
 * @size: The size of the array.
 */
void print_array(const int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

/**
 * sift_down - Maintains the max-heap property by sifting a node down.
 * @array: The array representing the heap.
 * @size: The size of the array.
 * @root: The index of the root of the subtree.
 * @end: The last index of the heap to consider.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left <= end && array[left] > array[largest])
        largest = left;

    if (right <= end && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        print_array(array, size);
        sift_down(array, size, largest, end);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    // Build max heap
    for (ssize_t i = (size / 2) - 1; i >= 0; i--)
        sift_down(array, size, i, size - 1);

    // Perform heap sort
    for (ssize_t end = size - 1; end > 0; end--)
    {
        int temp = array[0];
        array[0] = array[end];
        array[end] = temp;
        print_array(array, size);
        sift_down(array, size, 0, end - 1);
    }
}

int main(void)
{
    int array[] = {19, 22, 63, 105, 2, 46};
    size_t size = sizeof(array) / sizeof(array[0]);

    print_array(array, size);
    heap_sort(array, size);
    print_array(array, size);

    return (0);
}
