//
// Created by cyran on 21.03.18.
//

#ifndef MEASURETIME_INTQUEUE_H
#define MEASURETIME_INTQUEUE_H

#include <stdexcept>
#include <iostream>

/*
 * Integer queue implementation based on single-linked list.
 */
class IntQueue {
private:
    struct Node {
        int value;
        Node *next;

        explicit Node(const int &_value, Node *_next = nullptr) : value(_value),
                                                                  next(_next) {}
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

public:
    ~IntQueue();

    void enqueue(const int &elem);

    int dequeue();

    bool empty() noexcept;

    void display();
};

#endif //MEASURETIME_INTQUEUE_H
