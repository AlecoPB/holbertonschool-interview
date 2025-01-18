#include <stdio.h>

void print_array(int *array, size_t start, size_t end) {
    printf("Searching in array: ");
    for (size_t i = start; i < end; i++) {
        printf("%d", array[i]);
        if (i < end - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int binary_search(int *array, size_t start, size_t end, int value) {
    if (start >= end) {
        return -1; // Base case: not found
    }

    // Calculate the middle index
    size_t mid = start + (end - start) / 2;

    // Print the current subarray
    print_array(array, start, end);

    // Check if the middle element is the value we're looking for
    if (array[mid] == value) {
        // Check if it's the first occurrence
        if (mid == start || array[mid - 1] < value) {
            return mid; // Found the first occurrence
        } else {
            // Search in the left half
            return binary_search(array, start, mid, value);
        }
    } else if (array[mid] < value) {
        // Search in the right half
        return binary_search(array, mid + 1, end, value);
    } else {
        // Search in the left half
        return binary_search(array, start, mid, value);
    }
}

int advanced_binary(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1; // Handle NULL array or size 0
    }
    return binary_search(array, 0, size, value);
}

// Example usage
int main() {
    int array[] = {1, 2, 2, 2, 3, 4, 5};
    size_t size = sizeof(array) / sizeof(array[0]);
    int value = 2;

    int index = advanced_binary(array, size, value);
    if (index != -1) {
        printf("Value %d found at index: %d\n", value, index);
    } else {
        printf("Value %d not found in the array.\n", value);
    }

    return 0;
}
