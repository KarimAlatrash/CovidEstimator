#pragma once

class COVID_new_cases {
  public:
  double next_datum( double x );
  bool at_extreme() const;
};

// This is the worst-case predictor. If you do
// as bad as this you will get 0 on the project.
// The student who minimizes the test below will
// get 100%. Students will receive a grade linearly
// interpolated between these two values.

double COVID_new_cases::next_datum( double x ) {
  return x;
}

bool COVID_new_cases::at_extreme() const {
  return false;
}