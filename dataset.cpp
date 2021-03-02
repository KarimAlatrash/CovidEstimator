//
// Created by Karim Alatrash on 2021-02-27.
//

#include "dataset.h"

dataset::dataset(unsigned int max_length) {
    data_points = new queue(max_length);
    data_model = nullptr;
}

dataset::~dataset() {
    delete data_points;
    delete data_model;
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
vector* dataset::create_model(unsigned int max_order) {

    unsigned int data_size = current_data_size();
    double* data_array = data_as_array();

    /*for (int i = 0; i<data_size;i++) {
        std::cout << data_array[i] << ", ";
    }
    std::cout << std::endl;*/

    //sets # of columns based on the amount of data
    unsigned int cols;
    if (data_size >=max_order) cols = max_order+1;
    else cols = data_size; //minimum 2 columns!

    //creates vandermonde with all elements that are currently stored (up to max value)
    matrix vander = matrix::vander(data_size, cols, x_vals);

    vector v = vector{data_size, data_array};
    std::cout<<v<<std::endl;
    /*matrix t = transpose(vander) * vander;
    vector l = transpose(vander)*v;
    v=t.solve(l);
    std::cout <<"v is: " << v<<std::endl;
    std::cout <<"vander is: " << vander<<std::endl;
    */

    //solves the matrix for the LSBF polynomial
    v = (transpose(vander) * vander).solve(transpose(vander) * v );
    double* coeffs = new double[max_order+1]();

    std::cout << "model coefficients are: ";
    for (int i = 0; i < cols; ++i) {
        coeffs[i] = v(i);
        std::cout<<coeffs[i]<<", ";
    }
    std::cout<<std::endl;



    if (data_model != nullptr) {
        delete data_model;
    }
    data_model = new vector(max_order+1, coeffs);

    delete[] coeffs;

    return data_model;
}