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

  float exp(float fresh){
    float clean = 0;
    int i = 0, j = 0;

    while (i < 5, i++){
      history[i+1] = history[i];
    }

    history[0] = fresh;

    while (j < 5, j++){
      clean = clean + pow(1 - decay, j+1) * history[j];
    }

    return clean;
    }

};


#endif
