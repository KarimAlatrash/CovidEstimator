//
// Created by Karim Alatrash on 2021-02-27.
//

#ifndef COVIDESTIMATOR_DATASET_H
#define COVIDESTIMATOR_DATASET_H
#include "linalg.hpp"
#include "queue.h"


class dataset {
private:
    queue* data_points;
    vector* cubic_model;
public:
    dataset(unsigned int max_length);
    ~dataset();
    double* data_as_array();
    void add_data_point(double new_data_point);
    unsigned int current_data_size();
    vector* create_cubic_model();
};


#endif //COVIDESTIMATOR_DATASET_H
