//
// Created by Karim Alatrash on 2021-02-28.
//

#ifndef COVIDESTIMATOR_QUEUE_H
#define COVIDESTIMATOR_QUEUE_H
#include "node.h"


class queue {
private:
    node* front = nullptr;
    node* back = nullptr;
    void enqueue(node* new_elem);
    void dequeue();
    double* current_array = nullptr;
    unsigned int max_length_;
    unsigned int current_length_ = 0;
public:
    queue(unsigned int max_length);
    ~queue();
    void add_element(double new_element_val);
    double* get_array();
    unsigned int get_current_length();
    node* get_front() {
        return front;
    }
    node* get_back() {
        return back;
    }
};


#endif //COVIDESTIMATOR_QUEUE_H
