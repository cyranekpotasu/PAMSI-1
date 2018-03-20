//
// Created by cyran on 21.03.18.
//

#include <random>
#include "../lib/HeapSort.h"
#include "../lib/sorting.h"

HeapSort::~HeapSort() {
    delete[] data;
}

void HeapSort::prepare(unsigned _data_size) {
    delete[] data;
    data_size = _data_size;
    data = new int[data_size];

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, data_size * 2);
    for(int i = 0; i < data_size; i++)
        data[i] = dist(mt);
}

void HeapSort::run() {
    heap_sort(data, data_size);
}

