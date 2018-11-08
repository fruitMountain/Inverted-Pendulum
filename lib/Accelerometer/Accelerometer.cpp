#include <Arduino.h>
#include "Accelerometer.h"

Accelerometer::Accelerometer(int x1, int x2, int x3){
  PinX = x1;
  PinY = x2;
  PinZ = x3;
}

float Accelerometer::GetTheta(){
  float Theta = atan2(-1 * ReadY(),-1 * ReadX());
  return Theta;
}

void Accelerometer::Debug() {
  Serial.print("X= ");
  Serial.print(ReadX());
  Serial.print(" Y= ");
  Serial.println(ReadY());
}

// Function for reading X axis acceleration
float Accelerometer::ReadX(){
  int A = analogRead(PinX);
  float X = (A - 513.) / 100.;
  return X;
}

// Function for reading Y axis acceleration
float Accelerometer::ReadY(){
  int B = analogRead(PinY);
  float Y = (B - 513.) / 100.;
  return Y;
}

// Function for reading Z axis acceleration
float Accelerometer::ReadZ(){
  int C = analogRead(PinZ);
  float Z = (C - 513) / 100;
  return Z;
}
