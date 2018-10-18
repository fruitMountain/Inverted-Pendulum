#include <Arduino.h>
#include "Filter.h"

// Exponential Filter, arg is measured variable
float Filter::exp(float fresh){
  float clean = 0;
  int i = 0, j = 0;

  while (i < 5){
    history[i+1] = history[i];
    i = i + 1;
  }

  history[0] = fresh;

  while (j < 5){
    clean = clean + pow(1 - decay, j+1) * history[j];
    j = j + 1;
  }

  return clean;
}
