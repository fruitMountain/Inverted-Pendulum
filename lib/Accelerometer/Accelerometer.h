//Arduino
//Read basic accelerometer data

#ifndef ACCELEROMETER_H //checks to see if this is defined
#define ACCELEROMETER_H //defines it if the check passes
// This prevents this header from being called twice on accident

#include <Arduino.h> //allows us to use analogRead

class Accelerometer{
 public:
  Accelerometer(int x1, int x2, int x3);
  float GetTheta();
  void Debug();

 private:
  // Define variables for analog pins:
  int PinX, PinY, PinZ;

  float ReadX();
  float ReadY();
  float ReadZ();
};

#endif
