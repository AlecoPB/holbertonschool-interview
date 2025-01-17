#include <stdio.h>

/**
 * regex_match - compare two strings
 * @str: first string
 * @pattern: second string
 * Description: Compare two strings
 * Return: 1 or 0
 */
int regex_match(const char *str, const char *pattern)
{
/* Base case: If the pattern is empty */
if (*pattern == '\0')
{
return (*str == '\0' ? 1 : 0);
}

/* Check if the first character matches or if pattern starts with '.' */
int first_match = (*str != '\0') && (*str == *pattern || *pattern == '.');

/* Handle '*' in the pattern */
if (*(pattern + 1) == '*')
{
/* Skip the 'x*' in pattern or use the '*'*/
return (regex_match(str, pattern + 2) ||
(first_match && regex_match(str + 1, pattern)));
}
else
{
/* Regular matching for the first character */
return (first_match && regex_match(str + 1, pattern + 1));
}
}
