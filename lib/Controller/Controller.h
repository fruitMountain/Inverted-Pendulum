// Arduino
// Basic PID control

#pragma once

#include <Arduino.h> //allows us to use analogRead

class Controller{
 private:
  int Cp, Ci, Cd;
  int ESum;

  int Proportional(int error);
  int Integral(int error);
  int Derivative(int error);

 public:
  Controller(int x1, int x2, int x3);
  float PID(int error);
}

#endif
