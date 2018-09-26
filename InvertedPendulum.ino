#include "Accelerometer.h"
Accelerometer acc;

void setup(){
  Serial.begin(9600);

  // Define pins for the accelerometer
  acc.PinX = A0;
  acc.PinY = A1;
  acc.PinZ = A2;
}

void loop(){
  float Theta = acc.GetTheta();
  Serial.print(Theta);
}
