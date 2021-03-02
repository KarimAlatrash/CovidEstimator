//
// Created by Karim Alatrash on 2021-02-27.
//

#ifndef COVIDESTIMATOR_DATASET_H
#define COVIDESTIMATOR_DATASET_H
#include "linalg.hpp"
#include "queue.h"


class dataset {
private:
    queue* raw_data_points;
    vector* data_model;
    queue* current_cleansed_data = nullptr;
    //unsigned int current_cleansed_array_length;
    double standard_deviation(double array[], unsigned int array_length);
    double x_vals[120] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};

public:
    dataset(unsigned int max_length);
    unsigned int no_cleanse_counter{0};
    ~dataset();
    //double* data_as_array();
    queue* cleanse_data(double array[], unsigned int size);
    void add_data_point(double new_data_point);
    unsigned int current_data_size();
    vector* create_model(unsigned int max_order);
};


#endif //COVIDESTIMATOR_DATASET_H
