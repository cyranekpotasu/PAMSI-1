//
// Created by cyran on 19.03.18.
//

#ifndef MEASURETIME_MERGESORT_H
#define MEASURETIME_MERGESORT_H


#include "IRunnable.h"
#include "IPreparable.h"

class MergeSort: public IPreparable,
                 public IRunnable {
private:
    unsigned data_size = 0;
    int* data = nullptr;

public:
    ~MergeSort();

    void prepare(unsigned _data_size) override;
    void run() override;
    void print_data();
};


#endif //MEASURETIME_MERGESORT_H
