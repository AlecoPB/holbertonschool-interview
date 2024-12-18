#include <stdio.h> 
#include <ctype.h>
#include <substring.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    char num_str[50]; // Buffer to store the number as a string

    for (int i = 0; i < nb_words; i++) {
        int counter = 0;

        // Check if the last character is a digit; skip if already processed
        if (isdigit(words[i][strlen(words[i]) - 1])) {
            continue;
        }

        // Count occurrences of the current word
        for (int j = 0; j < nb_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                counter++;
            }
        }

        // Append the count to the current word
        sprintf(num_str, "%d", counter);
        strcat(words[i], num_str);
    }
}