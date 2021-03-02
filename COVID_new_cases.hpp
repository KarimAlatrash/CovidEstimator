#pragma once
#include "linalg.hpp"
#include "dataset.h"

class COVID_new_cases {
  public:
  double next_datum( double x );
  bool at_extreme() const;
private:
    dataset data{90};
    int max_order = 3;
    static double horners_eval(vector* poly, int order, double x_val);
};

// This is the worst-case predictor. If you do
// as bad as this you will get 0 on the project.
// The student who minimizes the test below will
// get 100%. Students will receive a grade linearly
// interpolated between these two values.

double COVID_new_cases::next_datum( double x ) {


    data.add_data_point(x);
    vector* data_model = data.create_model(max_order);

    //evaluate the cubic function at length+1
    double next_approx = horners_eval(data_model, max_order, data.current_data_size());

    std::cout <<std::endl;
    std::cout << "current day value is: " << x <<std::endl;
    std::cout << "next approximation is: " << next_approx <<std::endl;
    return next_approx;

}

//horners eval retrieved from the ece204 midterm formula sheet
double COVID_new_cases::horners_eval(vector* poly, int order, double x_val) {
    double result{ (*poly)(0) };
    for (int i{1}; i<=order; i++) {
        result += result*x_val + (*poly)(i);
    }
    return round(result);
}

//returns pointer to element 0 of array which contains data
/*
double* COVID_new_cases::cut_noise(vector cubic_lsbf_poly, double data[], unsigned int length) {
    unsigned int new_size{0};


    for (int i{0}; i<length; ++i) {
        double horner_result = horners_eval(cubic_lsbf_poly, 3, data[i]); //horners_eval might not work

        if(data[i] < horner_result+10 && data[i] > horner_result-10 ) {
            new_size++;
        }
        else {
            data[i] = -1;
        }
    }

    double* new_data = new double[new_size];
    unsigned int new_data_counter{0};
    for (int i = 0; i < length; i++) { //you might overflow on this loop!
        if(data[i] != -1) {
            new_data[new_data_counter] = data[i];
            new_data_counter++;
        }
    }
    return new_data;
}
*/
bool COVID_new_cases::at_extreme() const {
  return false;
}