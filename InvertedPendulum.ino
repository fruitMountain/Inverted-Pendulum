#include "Accelerometer.h"
#include "Motor.h"
Accelerometer acc;
Motor motor;

void setup(){
  Serial.begin(9600);
  while (! Serial); //Wait for serial to begin

  // Define pins for the accelerometer
  acc.PinX = A0;
  acc.PinY = A1;
  acc.PinZ = A2;

  motor.In1 = 3;
  motor.In2 = 8;
  motor.pwm = 9;
  motor.stby = 10;
  motor.startup();
}

void loop(){
  float Theta = acc.GetTheta();

  motor.Clockwise(255);
  motor.CounterClockwise(255);
  }
