#include <stdio.h>

/**
 * wildcmp - compare two strings
 * @s1: first string
 * @s2: second string
 * Description: Compare two strings
 * Return: 1 or 0
 */
int wildcmp(char *s1, char *s2) {
if (*s1 == '\0' && *s2 == '\0') {
// Both strings are fully traversed
return 1;
}
if (*s2 == '*') {
// * in s2 can match zero or more characters in s1
if (wildcmp(s1, s2 + 1)) {
return 1;
}
if (*s1 != '\0' && wildcmp(s1 + 1, s2)) {
return 1;
}
return 0;
}
if (*s1 == *s2) {
// Characters match, move to the next
return wildcmp(s1 + 1, s2 + 1);
}
// Characters do not match
return 0;
}
