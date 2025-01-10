#include "sort.h"
#include <stdio.h>

// Helper function to perform sift-down operation
void sift_down(int *array, size_t size, size_t root, size_t end) {
    size_t largest = root;
    size_t left_child = 2 * root + 1;
    size_t right_child = 2 * root + 2;

    // Check if the left child is larger than the current root
    if (left_child < end && array[left_child] > array[largest]) {
        largest = left_child;
    }

    // Check if the right child is larger than the largest so far
    if (right_child < end && array[right_child] > array[largest]) {
        largest = right_child;
    }

    // If the largest is not the root, swap and continue sifting down
    if (largest != root) {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        print_array(array, size); // Print the array after each swap

        sift_down(array, size, largest, end); // Recursively heapify the affected sub-tree
    }
}

// Heap sort function
void heap_sort(int *array, size_t size) {
    if (size < 2) {
        return; // No need to sort an array with less than 2 elements
    }

    // Build the max heap
    for (ssize_t i = (size / 2) - 1; i >= 0; i--) {
        sift_down(array, size, i, size);
    }

    // Extract elements from the heap one by one
    for (size_t end = size; end > 1; end--) {
        // Move the current root (max element) to the end
        int temp = array[0];
        array[0] = array[end - 1];
        array[end - 1] = temp;

        print_array(array, size); // Print the array after each swap

        // Restore the max heap property for the reduced heap
        sift_down(array, size, 0, end - 1);
    }
}
