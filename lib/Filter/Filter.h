//Arduino
//Filter Accelerometer readings

#ifndef FILTER_H // If filter_h is not a defined variable do the following
#define FILTER_H// Define filter_h as a variable.
// This way the following code only runs once.

#include <Arduino.h> //Allows arduino commands
#include <math.h>
#include "Accelerometer.h"


class Filter{
 public:
  float history[5] = {0,0,0,0,0};
  float decay;
  float fresh;

  float exp(float fresh);
};


#endif
