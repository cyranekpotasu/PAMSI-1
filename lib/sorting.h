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

void heapify(int* container, const int& size, const int& i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && container[left] > container[largest])
        largest = left;

    if(right < size && container[right] > container[largest])
        largest = right;

    if(largest != i) {
        std::swap(container[i], container[largest]);
        heapify(container, size, largest);
    }
}

void heap_sort(int* container, const int& size) {
    for(int i = size/2 - 1; i >= 0; i--)
        heapify(container, size, i);

    for(int i = size - 1; i >= 0; i--) {
        std::swap(container[0], container[i]);
        heapify(container, i, 0);
    }
}

void merge_sort(int* container, int n);
void quick_sort(int* container, int n);

#endif //MEASURETIME_SORTING_H
