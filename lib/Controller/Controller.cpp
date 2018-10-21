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
  ESum = ESum + error;
  return ESum;
}

int Controller::Derivative(int error){
  // TODO
  return error;
}

float PID(int error){
  temp = Proportional(error) + Integral(error) + Derivative(error);
}
