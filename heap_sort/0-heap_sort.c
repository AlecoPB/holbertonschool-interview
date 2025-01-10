#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Perform sift down operation
 * @array: array to perform opertion on
 * @size: size of the array
 * @root: root of the array
 * @end: end of the array
 * 
 * Return: Sifts down
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
size_t largest = root;
size_t left_child = 2 * root + 1;
size_t right_child = 2 * root + 2;

if (left_child < end && array[left_child] > array[largest])
{
largest = left_child;
}

if (right_child < end && array[right_child] > array[largest])
{
largest = right_child;
}

if (largest != root)
{
int temp = array[root];
array[root] = array[largest];
array[largest] = temp;

print_array(array, size);

sift_down(array, size, largest, end);
}
}

void heap_sort(int *array, size_t size)
{
if (size < 2)
{
return;
}

for (ssize_t i = (size / 2) - 1; i >= 0; i--)
{
sift_down(array, size, i, size);
}

for (size_t end = size; end > 1; end--)
{
int temp = array[0];
array[0] = array[end - 1];
array[end - 1] = temp;

print_array(array, size);

sift_down(array, size, 0, end - 1);
}
}
