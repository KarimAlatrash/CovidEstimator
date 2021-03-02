#include <iostream>
#include <cmath>
#include "data.hpp"
#include "COVID_new_cases.hpp"

//https://towardsdatascience.com/an-introduction-to-support-vector-regression-svr-a3ebc1672c2
//THAT ARTICLE ^^ TELLS YOU HOW TO ADD ERROR TOLERANCE TO YOUR DATA SET


// Function declarations
int main();
double test( double array[], unsigned int capacity );

// Function definitions
int main() {
  for ( std::size_t k{0}; k < DATA_MAX; ++k ) {
    std::cout << test( data[k], 1000 )
              << std::endl;
  }
 return 0;
}
// Calculate the root-mean-squared-error (RMSE).
double test( double array[],
             unsigned int capacity ) {
  COVID_new_cases obj{};
  double squared_error{ 0.0 };
  //unsigned int day_counter{0};
  for ( unsigned int k{capacity - 1}; k > 0; --k ) {
      //std::cout <<"day count is: "<<day_counter<<std::endl;
      //day_counter++;
    double prediction { obj.next_datum( array[k] ) };
    squared_error +=
        std::pow( prediction - array[k - 1], 2.0 );
  }

  return std::sqrt( squared_error/capacity );
}