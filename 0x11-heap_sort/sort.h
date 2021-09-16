#ifndef SORT_H
#define SORT_H
#include <stdlib.h>

void print_array(const int* array, size_t size);
void heap_sort(int* array, size_t size);
void move(int* arr, int start, int end, size_t size);
void heap(int* arr, size_t size, int i);

#endif