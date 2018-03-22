//
// Created by cyran on 21.03.18.
//
#include "../lib/IntQueue.h"

IntQueue::~IntQueue() {
    Node* iter = head;

    while(iter != nullptr) {
        Node* next = iter->next;
        delete iter;
        iter = next;
    }
}

void IntQueue::enqueue(const int &elem) {
    auto new_node = new Node(elem);
    if(tail == nullptr)
        tail = head = new_node;
    else {
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

int IntQueue::dequeue() {
    if(empty())
        throw std::runtime_error("Trying to enqueue from empty queue.");

    Node* next = head->next;
    int elem = head->value;

    delete head;
    head = next;

    if(head == nullptr)
        tail = nullptr;
    size--;
    return elem;
}

bool IntQueue::empty() noexcept {
    return head == nullptr;
}

void IntQueue::display() {
    Node* iter = head;
    while(iter != nullptr) {
        std::cout << iter->value << ' ';
        iter = iter->next;
    }
    std::cout << std::endl;
}

int IntQueue::front() {
    return head->value;
}
