//
// Created by Karim Alatrash on 2021-02-27.
//

#include "dataset.h"

dataset::dataset(unsigned int max_length) {
    raw_data_points = new queue(max_length);
    data_model = nullptr;
}

dataset::~dataset() {
    delete raw_data_points;
    delete data_model;
}

double dataset::standard_deviation(double array[], unsigned int array_length) {
    double mean{0};
    for (int i = 0; i<array_length; i++) {
        mean+=array[i];
    }
    mean = mean/array_length;

    double std_dev{0};
    for (int i = 0; i<array_length; i++) {
        std_dev += pow(array[i] - mean, 2);
    }

    return sqrt(std_dev/10);
}

queue* dataset::cleanse_data(double array[], unsigned int size) {
    double std_dev = standard_deviation(array, size);
    //std::cout<<"standard deviation is: "<<std_dev<<std::endl;

    queue* cleansed_data = new queue(size);

    cleansed_data->add_element(array[0]);
    //loop through entire data structure,
    //add to cleansed data if diff of 2 points is < std deviation
    for (int i{1}; i<size; i++) {
        if(abs(array[i] - array[i-1]) <= std_dev) {
            cleansed_data->add_element(array[i]);
        }
    }

    return cleansed_data;
}
void dataset::add_data_point(double new_data_point) {
    raw_data_points->add_element(new_data_point);
}
unsigned int dataset::current_data_size() {
    return raw_data_points->get_current_length();
}

vector* dataset::create_model(unsigned int max_order) {

    delete current_cleansed_data;
    current_cleansed_data = cleanse_data(raw_data_points->get_array(), raw_data_points->get_current_length());
    unsigned int data_size = current_cleansed_data->get_current_length();
    double* data_array = current_cleansed_data->get_array();
    //unsigned int data_size = raw_data_points->get_current_length(); //raw dataa points
    //double* data_array = raw_data_points->get_array();


    for (int i = 0; i<data_size;i++) {
        std::cout << data_array[i] << ", ";
    }
    std::cout << std::endl;

    //sets # of columns based on the amount of data
    unsigned int cols;
    if (data_size >=max_order) cols = max_order+1;
    else cols = data_size; //minimum 2 columns!

    //creates vandermonde with all elements that are currently stored (up to max value)
    matrix vander = matrix::vander(data_size, cols, x_vals);

    vector v = vector{data_size, data_array};
    //std::cout <<"v is: " << v<<std::endl;
    //std::cout <<"vander is: " << vander<<std::endl;


    //solves the matrix for the LSBF polynomial
    v = (transpose(vander) * vander).solve(transpose(vander) * v );
    double* coeffs = new double[max_order+1]();

    //std::cout << "model coefficients are: ";
    for (int i = 0; i < cols; ++i) {
        coeffs[i] = v(i);
        //std::cout<<coeffs[i]<<", ";
    }
    //std::cout<<std::endl;



    delete data_model;
    data_model = new vector(max_order+1, coeffs);

    delete[] coeffs;

    return data_model;
}