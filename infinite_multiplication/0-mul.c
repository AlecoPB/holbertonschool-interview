#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit - Checks if a string is composed only of digits.
 * @s: The string to check.
 * Return: 1 if the string is numeric, 0 otherwise.
 */
int is_digit(char *s)
{
    while (*s)
    {
        if (!isdigit(*s))
            return (0);
        s++;
    }
    return (1);
}

/**
 * allocate_result - Allocates and initializes a result array.
 * @size: Size of the array.
 * Return: Pointer to the allocated array.
 */
char *allocate_result(size_t size)
{
    char *result = calloc(size + 1, sizeof(char));
    if (!result)
    {
        printf("Error\n");
        exit(98);
    }
    return (result);
}

/**
 * multiply - Multiplies two strings representing positive numbers.
 * @num1: First number as a string.
 * @num2: Second number as a string.
 * Return: The product as a string.
 */
char *multiply(char *num1, char *num2)
{
    size_t len1 = strlen(num1), len2 = strlen(num2);
    size_t result_size = len1 + len2;
    char *result = allocate_result(result_size);
    int carry, temp;

    /* Initialize result to '0' */
    for (size_t i = 0; i < result_size; i++)
        result[i] = '0';

    /* Perform multiplication */
    for (ssize_t i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (ssize_t j = len2 - 1; j >= 0; j--)
        {
            temp = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = temp / 10;
            result[i + j + 1] = (temp % 10) + '0';
        }
        result[i] += carry;
    }

    /* Remove leading zeros */
    while (*result == '0' && *(result + 1))
        result++;

    return strdup(result);
}

/**
 * main - Entry point. Multiplies two positive numbers.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char **argv)
{
    char *result;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
    {
        printf("Error\n");
        return (98);
    }

    result = multiply(argv[1], argv[2]);
    printf("%s\n", result);

    free(result); /* Free dynamically allocated memory */
    return (0);
}
