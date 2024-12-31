#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned integer is a palindrome.
 * @n: The number to be checked.
 *
 * Return: 1 if n is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
    unsigned long original = n, reversed = 0, remainder;

    while (n != 0)
    {
        remainder = n % 10;            /* Extract the last digit */
        reversed = reversed * 10 + remainder; /* Build reversed number */
        n /= 10;                       /* Remove the last digit */
    }

    return (original == reversed);     /* Compare original with reversed */
}
