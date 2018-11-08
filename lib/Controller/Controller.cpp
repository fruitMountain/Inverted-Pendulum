#include <Arduino.h>
#include "Controller.h"

Controller::Controller(int x1,int x2,int x3){
  Cp = x1;
  Ci = x2;
  Cd = x3;
}

int Controller::Proportional(int error){
  return (error * Cp);
}

int Controller::Integral(int error){
  int ESum = ESum + error;
  return ESum;
}

int Controller::Derivative(int error){
  int Ediff = error - Emem;
  Emem = error
  return Ediff;
}

float PID(int error){
  int gain = Proportional(error) + Integral(error) + Derivative(error);
  return(gain)
}
