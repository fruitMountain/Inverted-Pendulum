//Arduino
//Read basic accelerometer data

#ifndef ACCELEROMETER_H //checks to see if this is defined
#define ACCELEROMETER_H //defines it if the check passes
// This prevents this header from being called twice on accident

#include <Arduino.h> //allows us to use analogRead

class Accelerometer{
 public:
  // The Constructor
  Accelerometer(int x1, int x2, int x3){
    PinX = x1;
    PinY = x2;
    PinZ = x3;
  }

  // A function for returning the angle of the accelerometer rotated on the z axis
  float GetTheta(){
    float Theta = atan2(-1*ReadX(),-1*ReadY());
    return Theta;
  }

  void Debug() {
    Serial.print("X= ");
    Serial.print(analogRead(PinX));
    Serial.print(" Y= ");
    Serial.println(analogRead(PinY));
  }

 private:
  // Define variables for analog pins:
  int PinX, PinY, PinZ;

  // Function for reading X axis acceleration
  float ReadX(){
    int A = analogRead(PinX);
    float X = (A - 513) / 100;
    return X;
  };

  // Function for reading Y axis acceleration
  float ReadY(){
    int B = analogRead(PinY);
    float Y = (B - 513) / 100;
    return Y;
  };

  // Function for reading Z axis acceleration
  float ReadZ(){
    int C = analogRead(PinZ);
    float Z = (C - 513) / 100;
    return Z;
  };

};

#endif
