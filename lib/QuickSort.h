//
// Created by cyran on 22.03.18.
//

#ifndef MEASURETIME_QUICKSORT_H
#define MEASURETIME_QUICKSORT_H

#include "IRunnable.h"
#include "IPreparable.h"
#include "sorting.h"

class QuickSort: public IPreparable,
                 public IRunnable {
private:
    int* data = nullptr;
    unsigned data_size = 0;

public:
    ~QuickSort() {
        delete[] data;
    }

    void prepare(unsigned _data_size,
                 const Case& exp_case) override;

    void run() override;

    void print_data();
};

#endif //MEASURETIME_QUICKSORT_H
