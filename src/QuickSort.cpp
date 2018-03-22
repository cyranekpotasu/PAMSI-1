//
// Created by cyran on 22.03.18.
//

#include <random>
#include <iostream>
#include "../lib/IPreparable.h"
#include "../lib/QuickSort.h"

void QuickSort::prepare(unsigned _data_size, const Case &exp_case) {
    delete[] data;
    data_size = _data_size;

    data = new int[data_size];

    if (exp_case == Case::average) {
//        std::random_device rd;
//        std::mt19937 mt(rd());
//        std::uniform_int_distribution<int> dist(0, data_size * 2);
//        for (int i = 0; i < data_size; i++)
//            data[i] = dist(mt);
        for (int i = 0; i < data_size; i++)
            data[i] = rand() % data_size;
    }
//    else if (exp_case == Case::worst) {
//        for (int i = 0; i < data_size; i++)
//            data[i] = i;
//    }
}

void QuickSort::run() {
    quick_sort(data, 0, data_size - 1);
}

void QuickSort::print_data() {
    for(int i = 0; i < data_size; i++)
        std::cout << data[i] << ' ';
    std::cout << std::endl;
}
