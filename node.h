//
// Created by Karim Alatrash on 2021-02-28.
//

#ifndef COVIDESTIMATOR_NODE_H
#define COVIDESTIMATOR_NODE_H


class node {
private:
    node* next = nullptr;
    node* previous = nullptr;

public:
    node(double value_) {
        value = value_;
    }

    ~node() {

    }

    node* get_next();
    node* get_previous();
    void set_next(node* new_next);
    void set_previous(node* new_previous);
    double value;
};


#endif //COVIDESTIMATOR_NODE_H
