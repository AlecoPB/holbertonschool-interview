#include "sort.h"
#include <stdio.h>

void print_array(const int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

void sift_down(int *array, size_t size, size_t root, size_t end) {
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left <= end && array[left] > array[largest]) {
        largest = left;
    }
    if (right <= end && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != root) {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        print_array(array, size); // Print after each swap
        sift_down(array, size, largest, end);
    }
}

void heap_sort(int *array, size_t size) {
    if (!array || size < 2) return;

    // Build the max heap
    for (ssize_t i = (size / 2) - 1; i >= 0; i--) {
        sift_down(array, size, i, size - 1);
    }

    // Perform heap sort
    for (size_t end = size - 1; end > 0; end--) {
        // Swap the root(maximum element) with the end of the heap
        int temp = array[0];
        array[0] = array[end];
        array[end] = temp;
        print_array(array, size); // Print after each swap

        // Restore the heap property for the reduced heap
        sift_down(array, size, 0, end - 1);
    }
}
