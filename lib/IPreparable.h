//
// Created by cyran on 03.03.18.
//

#ifndef MEASURETIME_IPREPARABLE_H
#define MEASURETIME_IPREPARABLE_H

//enum class Case {pesimistic, average, optimistic};

class IPreparable {
public:
    virtual void prepare(unsigned int data_size) = 0;
};

#endif //MEASURETIME_IPREPARABLE_H
