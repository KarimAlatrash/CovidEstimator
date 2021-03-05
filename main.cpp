#include <iostream>
#include <cmath>
#include "data.hpp"
#include "COVID_new_cases.hpp"

// Function declarations
int main();
double test( double array[], unsigned int capacity );

// Function definitions
int main() {
    double avg{0};
    for ( std::size_t k{0}; k < DATA_MAX; ++k ) {
        avg+=test( data[k], 1000 );
        //std::cout << test( data[k], 1000 )
        //          << std::endl;
    }
    std::cout<<"Avg: "<<avg/DATA_MAX<<std::endl;
    return 0;
}
// Calculate the root-mean-squared-error (RMSE).
double test( double array[],
             unsigned int capacity ) {
    COVID_new_cases obj{};
    double squared_error{ 0.0 };

    for ( unsigned int k{capacity - 1}; k > 0; --k ) {
        double prediction { obj.next_datum( array[k] ) };
        squared_error +=
                std::pow( prediction - array[k - 1], 2.0 );
    }

    return std::sqrt( squared_error/capacity );
}