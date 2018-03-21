//
// Created by cyran on 15.03.18.
//

/*
 * Sorting library with implementations of
 * heap sort, merge sort and quick sort
 */

#ifndef MEASURETIME_SORTING_H
#define MEASURETIME_SORTING_H


#include <utility>

void heapify(int *container, const int &size, const int &i);
void heap_sort(int *container, int size);
void merge(int* container, int left, int mid, int right);
void merge_sort(int *container, int low, int high);
int partition(int* arr, int low, int high);
void quick_sort(int *container, int low, int high);

#endif //MEASURETIME_SORTING_H
