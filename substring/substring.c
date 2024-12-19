#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper function to check if a substring matches the concatenation of words
bool matches_words(const char *s, const char **words, int nb_words, int word_len, int *word_freq)
{
int *seen = calloc(nb_words, sizeof(int));
if (!seen)return (false);

for (int i = 0; i < nb_words; i++)
{
bool found = false;
for (int j = 0; j < nb_words; j++)
{
if (strncmp(s + i * word_len, words[j], word_len)== 0 && seen[j] < word_freq[j])
{
seen[j]++;
found = true;
break;
}
}
if (!found)
{
free(seen);
return (false);
}
}

free(seen);
return (true);
}

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
if (!s || !words || nb_words == 0)
{
*n = 0;
return (NULL);
}

int word_len = strlen(words[0]);
int substring_len = nb_words * word_len;
int s_len = strlen(s);

if (substring_len > s_len)
{
*n = 0;
return (NULL);
}

int *result = malloc(s_len * sizeof(int));
if (!result)return (NULL);

int result_count = 0;

// Create a frequency map of words
int *word_freq = calloc(nb_words, sizeof(int));
if (!word_freq)
{
free(result);
return (NULL);
}

for (int i = 0; i < nb_words; i++)
{
for (int j = 0; j < nb_words; j++)
{
if (strcmp(words[i], words[j]) == 0)
{
word_freq[i]++;
}
}
}

// Iterate through the string to find valid substrings
for (int i = 0; i <= s_len - substring_len; i++)
{
if (matches_words(s + i, words, nb_words, word_len, word_freq))
{
result[result_count++] = i;
}
}

free(word_freq);

// Resize the result array to the exact number of found substrings
result = realloc(result, result_count * sizeof(int));
*n = result_count;

if (result_count == 0)
{
free(result);
return (NULL);
}

return (result);
}
