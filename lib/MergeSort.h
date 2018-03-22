//
// Created by cyran on 19.03.18.
//

#ifndef MEASURETIME_MERGESORT_H
#define MEASURETIME_MERGESORT_H


#include <random>
#include <iostream>
#include "IRunnable.h"
#include "IPreparable.h"
#include "../lib/sorting.h"

class MergeSort: public IPreparable,
                 public IRunnable {
private:
    unsigned data_size = 0;
    int* data = nullptr;

public:
    ~MergeSort();

    void prepare(unsigned _data_size,
                 const Case& exp_case) override;
    void prepare(unsigned _data_size) {
        prepare(_data_size, Case::average);
    }
    void run() override;
    void print_data();
};


#endif //MEASURETIME_MERGESORT_H
