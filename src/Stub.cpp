//
// Created by cyran on 03.03.18.
//

#include "../lib/Stub.h"

Stub::~Stub() {
    delete[] data;
}

void Stub::prepare(unsigned int _data_size) {
    delete[] data;
    data_size = _data_size;
    data = new int[data_size];
}

void Stub::run() {
    std::this_thread::sleep_for(std::chrono::microseconds(data_size));
}
