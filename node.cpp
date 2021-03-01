//
// Created by Karim Alatrash on 2021-02-28.
//

#include "node.h"

node* node::get_next() {
    return next;
}
void node::set_next(node* new_next) {
    next = new_next;
}
node* node::get_previous() {
    return previous;
}
void node::set_previous(node* new_previous) {
    previous = new_previous;
}