//Arduino
//Filter Accelerometer readings

#pragma once
// This way the following code only runs once.

#include <Arduino.h> //Allows arduino commands
#include <math.h>
#include "Accelerometer.h"


class Filter{
 private:
  // These better darn well be the same number, or else!
  const int terms = 5;
  float history[5];

  float decay;

 public:
  Filter(float x1);
  float exp(float fresh);
};
