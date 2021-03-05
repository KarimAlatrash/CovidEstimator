#pragma once
#include "linalg.hpp"
#include "dataset.h"
#include <cmath>

class COVID_new_cases {
  public:
  double next_datum( double x );
  bool at_extreme() const;


private:
    dataset data{25}; //best length is 25
    int max_order{1}; //best order is 1
    static double horners_eval(vector* poly, int order, double x_val);

};

double COVID_new_cases::next_datum( double x) {

    data.add_data_point(x);
    vector* data_model = data.create_model(max_order);

    //evaluate the cubic function at length+1
    double next_approx = horners_eval(data_model, max_order, data.current_cleansed_data_size());


    //std::cout <<std::endl;
    //std::cout << "current day value is: " << x <<std::endl;
    //std::cout << "next approximation is: " << next_approx <<std::endl;
    //delete data_model;
    return next_approx;

}

//horners eval retrieved from the ece204 midterm formula sheet
double COVID_new_cases::horners_eval(vector* poly, int order, double x_val) {
    double result{ (*poly)(0) };
    for (int i{1}; i<=order; i++) {
        result += result*x_val + (*poly)(i);
    }
    if (result < 0 ) {
        //std::cout << "coefficients are: "<<*poly<<std::endl;
        //throw std::length_error{"no negative approximations"};
        return 0;
    }

    return round(result);
}

bool COVID_new_cases::at_extreme() const {
  return false;
}