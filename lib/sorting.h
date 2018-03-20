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

void heapify(int *container, const int &size, const int &i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && container[left] > container[largest])
        largest = left;

    if (right < size && container[right] > container[largest])
        largest = right;

    if (largest != i) {
        std::swap(container[i], container[largest]);
        heapify(container, size, largest);
    }
}

void heap_sort(int *container, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(container, size, i);

    for (int i = size - 1; i >= 0; i--) {
        std::swap(container[0], container[i]);
        heapify(container, i, 0);
    }
}

void merge(int* container, int left, int mid, int right)
{
    int i, j, k;
    int left_size = mid - left + 1;
    int right_size =  right - mid;

    auto L = new int[left_size];
    auto R = new int[right_size];

    for (i = 0; i < left_size; i++)
        L[i] = container[left + i];
    for (j = 0; j < right_size; j++)
        R[j] = container[mid + 1+ j];

    i = 0;
    j = 0;
    k = left;
    while (i < left_size && j < right_size)
    {
        if (L[i] <= R[j])
        {
            container[k] = L[i];
            i++;
        }
        else
        {
            container[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        container[k] = L[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        container[k] = R[j];
        j++;
        k++;
    }
    delete[] R;
    delete[] L;
}

void merge_sort(int *container, int low, int high) {
    int middle;

    if (low < high) {
        middle = (low + high) / 2;
        merge_sort(container, low, middle);
        merge_sort(container, middle + 1, high);
        merge(container, low, middle, high);
    }
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++) {
        if(arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return i + 1;
}

void quick_sort(int *container, int low, int high) {
    if(low < high) {
        int part = partition(container, low, high);

        quick_sort(container, low, part - 1);
        quick_sort(container, part + 1, high);
    }
}

#endif //MEASURETIME_SORTING_H
