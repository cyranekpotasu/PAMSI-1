//
// Created by cyran on 21.03.18.
//

#include "../lib/HeapSort.h"

HeapSort::~HeapSort() {
    delete[] data;
}

void HeapSort::prepare(unsigned _data_size,
                       const Case& exp_case) {
    delete[] data;
    data_size = _data_size;
    data = new int[data_size];

    if (exp_case == Case::average) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, data_size * 2);
        for (int i = 0; i < data_size; i++)
            data[i] = dist(mt);
    } else if (exp_case == Case::best) {
        for (int i = 0; i < data_size; i++)
            data[i] = i;
    }
    else {
        for(int i = data_size - 1; i >= 0; i--)
            data[i] = i;

    }
}

void HeapSort::run() {
    heap_sort(data, data_size);
}

