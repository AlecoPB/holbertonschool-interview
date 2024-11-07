#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int get_max(int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void counting_sort_by_digit(int *array, size_t size, int exp) {
    int *output = (int *)malloc(size * sizeof(int));
    int count[10] = {0};

    // Store count of occurrences for each digit (0-9)
    for (size_t i = 0; i < size; i++) {
        int digit = (array[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so it contains the actual position of this digit in output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array based on current digit
    for (int i = size - 1; i >= 0; i--) {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    // Copy the output array to array, so that array now contains sorted numbers by current digit
    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
}

void radix_sort(int *array, size_t size) {
    if (size <= 1) return;

    // Find the maximum number to know the number of digits
    int max = get_max(array, size);

    // Perform counting sort for every digit. Exp is 10^i (1, 10, 100, ...)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort_by_digit(array, size, exp);
        print_array(array, size);  // Print array after sorting by each digit
    }
}

// Example main to test the function
int main() {
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    print_array(array, size);

    printf("Sorting process:\n");
    radix_sort(array, size);

    printf("Sorted array:\n");
    print_array(array, size);

    return 0;
}
