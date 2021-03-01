//
// Created by Karim Alatrash on 2021-02-27.
//

#include "dataset.h"

dataset::dataset(unsigned int max_length) {
    data_points = new queue(max_length);
    cubic_model = nullptr;
}

dataset::~dataset() {
    delete data_points;
    delete cubic_model;
}
double* dataset::data_as_array() {
    return data_points->get_array();
}
void dataset::add_data_point(double new_data_point) {
    data_points->add_element(new_data_point);
}
unsigned int dataset::current_data_size() {
    return data_points->get_current_length();
}
vector* dataset::create_cubic_model() {
    double* x_vals = new double[current_data_size()];
    for (int i = 0; i < current_data_size(); i++) {
        x_vals[i] = i;
    }

    //creates vandermonde with all elements that are currently stored (up to max value)
    matrix vander_O3 = matrix::vander(current_data_size(),5, x_vals);

    vector v = vector{current_data_size(), data_as_array()};
    v = (transpose(vander_O3)*vander_O3).solve( transpose(vander_O3)*v );
    double coeffs[4] = {v(0),v(1),v(2),v(3)};

    if (cubic_model != nullptr) {
        delete cubic_model;
    }
    cubic_model = new vector(4, coeffs);

    delete[] x_vals;

    return cubic_model;
}