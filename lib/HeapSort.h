//
// Created by cyran on 21.03.18.
//

#ifndef MEASURETIME_HEAPSORT_H
#define MEASURETIME_HEAPSORT_H

#include "IRunnable.h"
#include "IPreparable.h"

class HeapSort: public IPreparable,
                public IRunnable {
private:
    int* data = nullptr;
    unsigned data_size = 0;

public:
    ~HeapSort();

    void prepare(unsigned _data_size) override;
    void run() override;
};

#endif //MEASURETIME_HEAPSORT_H
