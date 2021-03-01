//
// Created by Karim Alatrash on 2021-02-28.
//

#include "queue.h"

queue::queue(unsigned int max_length) {
    max_length_ = max_length;
    current_length_= 0;
}
queue::~queue() {
    node* temp = front;
    while (front != back) {
        front = temp->get_next();
        delete temp;
        temp = front;
    }
    delete front;
}
void queue::enqueue(node* new_elem) {

    if(current_length_ ==0) {
        front = new_elem;
        back = new_elem;
    }
    else {
        new_elem->set_next(front);
        new_elem->set_previous(nullptr);
        front = new_elem;
    }
}

void queue::dequeue() {
    node* temp = back;
    back = back->get_previous();
    delete temp;
}

void queue::add_element(double new_element) {
    node* new_element_ = new node(new_element);
    if (current_length_ == max_length_) {
        dequeue();
    }
    enqueue(new_element_);
}

double* queue::get_array() {
    if (current_array != nullptr) {
        delete[] current_array;
    }
    current_array = new double[current_length_];
    node* nextptr = back;
    unsigned int counter{0};
    while (nextptr!= nullptr) {
        current_array[counter] = nextptr->value;
        counter++;
        nextptr = nextptr->get_previous();
    }
    return current_array;
}

unsigned int queue::get_current_length() {
    return current_length_;
}