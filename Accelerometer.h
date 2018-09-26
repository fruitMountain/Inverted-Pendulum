//Arduino
//Read basic accelerometer data

#ifndef ACCELEROMETER_H //checks to see if this is defined
#define ACCELEROMETER_H //defines it if the check passes
// This prevents this header from being called twice on accident

#include <Arduino.h> //allows us to use analogRead

class Accelerometer{
 public:
  // Define variables for analog pins:
  int PinX, PinY, PinZ;
  //Define variables for handling readout
  float A, B, C, X, Y, Z, Theta;

  // Function for reading X axis acceleration
  float ReadX(){
    A = analogRead(PinX);
    X = (A - 330) / 62;
    return X;
  };

  // Function for reading Y axis acceleration
  float ReadY(){
  B = analogRead(PinY);
  Y = (B - 330) / 60;
  return Y;
  };

  // Function for reading Z axis acceleration
  float ReadZ(){
  C = analogRead(PinZ);
  Z = (C - 330) / 71;
  return Z;
  };

  // A function for returning the angle of the accelerometer rotated on the z axis
  float GetTheta(){
    Theta = atan2(ReadY(),ReadX());
    return Theta;
  }
};

  /*
  Serial.print("X = ");
  Serial.print(A);
  Serial.print("\t");
  Serial.println(X);
  Serial.print("Y = ");
  Serial.print(B);
  Serial.print("\t");
  Serial.println(Y);
  Serial.print("Z = ");
  Serial.print(C);
  Serial.print("\t");
  Serial.println(Z);
  */

/*
  Theta = atan2(Y,X);
  Serial.print(Theta);

  delay(500);
}
*/

/*
  -1G = 260
  0 G = 330
  1 G = 390
*/

#endif
