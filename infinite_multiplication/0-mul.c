#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_positive_number(char *str);
void print_error_and_exit();

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 3) {
        print_error_and_exit();
    }

    // Check if both arguments are positive numbers
    if (!is_positive_number(argv[1]) || !is_positive_number(argv[2])) {
        print_error_and_exit();
    }

    // Convert arguments to integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    // Perform multiplication
    int result = num1 * num2;

    // Print the result followed by a new line
    printf("%d\n", result);

    return 0;
}

// Function to check if a string is a positive number
int is_positive_number(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // Not a positive number
        }
    }
    return 1; // Is a positive number
}

// Function to print error message and exit with status 98
void print_error_and_exit() {
    printf("Error\n");
    exit(98);
}
