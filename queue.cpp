//
// Created by Karim Alatrash on 2021-02-28.
//

#include "queue.h"

queue::queue(unsigned int max_length) {
    max_length_ = max_length;
    current_length_= 0;
}
queue::~queue() {
    node* temp = back;
    while (back != front) {
        back = temp->get_next();
        delete temp;
        temp = back;
    }
    delete front;
    delete[] current_array;
}
void queue::enqueue(node* new_elem) {

    if(current_length_ == 0) {
        front = new_elem;
        back = new_elem;
    }
    else {
        new_elem->set_next(back);
        back->set_previous(new_elem);
        back = new_elem;
    }
    current_length_++;
}

void queue::dequeue() {
    if(front == nullptr || front->get_next() == nullptr) {
        delete front;
        front = nullptr;
        back = nullptr;
        current_length_=0;
    }
    else {
        node* temp = front;
        front = front->get_previous();
        delete temp;
        current_length_--;
    }


}

void queue::add_element(double new_element_val) {
    node* new_element_ = new node(new_element_val);
    if (current_length_ == max_length_) {
        dequeue();
        enqueue(new_element_);
    }
    else {
        enqueue(new_element_);

    }
}

double* queue::get_array() {
    if (current_array != nullptr) {
        delete[] current_array;
    }
    current_array = new double[current_length_];
    node* nextptr = front;
    unsigned int counter{0};
    //feeds in the values to the array reverse to go from oldest to newest
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