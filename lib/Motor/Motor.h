// Arduino
// Write to electric motor

#pragma once
// This prevents this header from being called twice on accident

#include <Arduino.h> //allows us to use analogRead

class Motor{
 private:
  // Define variables for pins and stuff:
  int In1, In2, pwm, stby;
  int NewSpeed, OldSpeed = 0;
  int speed;

 public:
  //Constructor
  Motor(int x1, int x2, int x3, int x4);
  void startup();

  // Function for turning motor
  void Clockwise(int speed);

  // Literally the same as clockwise except toggled High and Low
  void CounterClockwise(int speed);

  // A function for turning everything off
  void Stop();

  // Quick function for alternating the motor
  void debug();
};
