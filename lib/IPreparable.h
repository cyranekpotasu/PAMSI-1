//
// Created by cyran on 03.03.18.
//

#ifndef MEASURETIME_IPREPARABLE_H
#define MEASURETIME_IPREPARABLE_H

enum class Case {best, average, worst};

class IPreparable {
public:
    virtual void prepare(unsigned int data_size,
                         const Case& exp_case) = 0;
};

#endif //MEASURETIME_IPREPARABLE_H
