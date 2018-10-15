#include "Accelerometer.h"
#include "Motor.h"
#include "Filter.h"

Accelerometer acc(A0, A1, A2);
Motor motor(3,8,9,10);
Filter filter;

void setup(){
  Serial.begin(9600);
  while (! Serial); //Wait for serial to begin
  motor.startup(); // Calls a function to
}

void loop(){
  float Theta = acc.GetTheta();
  float CleanTheta = filter.exp(Theta);
  }
