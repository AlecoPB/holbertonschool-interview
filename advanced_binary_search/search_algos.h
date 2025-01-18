#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <stdio.h>

int advanced_binary(int *array, size_t size, int value);
int recursive_binary(int *array, size_t left, size_t right, int value);
void print_sub_array(const int *array, size_t left, size_t right);

#endif