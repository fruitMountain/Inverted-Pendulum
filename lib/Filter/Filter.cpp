#include <Arduino.h>
#include "Filter.h"

// Constructor
Filter::Filter(float x1){
  decay = x1;
  }

float clean;

// Exponential Filter, arg is measured variable
float Filter::exp(float fresh){
  int i = terms - 2;
  int j = 0;
  clean = 0;

  // Shifting terms in array right
  while (i >= 0){
    history[i+1] = history[i];
    i = i - 1;
  }
  history[0] = fresh;

  // Averaging terms with exponentially decaying weights
  while (j < terms){
    clean = clean + pow(1 - decay, j+1) * history[j];
    j = j + 1;
  }

  return clean;
}
