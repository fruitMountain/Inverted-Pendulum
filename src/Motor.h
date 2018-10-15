// Arduino
// Write to electric motor

#ifndef MOTOR_H //checks to see if this is defined
#define MOTOR_H //defines it if the check passes
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
  Motor(int x1, int x2, int x3, int x4){
    pwm = x1;
    In1 = x2;
    In2 = x3;
    stby = x4;
  }

  void startup(){
    // Define pin modes, pins found in main setup
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(pwm, OUTPUT);
    pinMode(stby, OUTPUT);
    digitalWrite(stby, HIGH);
  };

  // Function for turning motor
  void Clockwise(int speed){
    // Tell the motor which direction you want
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);

    // This avoids writing unnecessary speeds, or speeds outside bounds
    NewSpeed = speed;
    if (NewSpeed != OldSpeed){
      if (speed >= 0 && speed <= 255){
        analogWrite(pwm, speed);
        OldSpeed = NewSpeed;
      }
    }
  }

  // Literally the same as clockwise except toggled High and Low
  void CounterClockwise(int speed){
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);

      NewSpeed = speed;
      if (NewSpeed != OldSpeed){
        if (speed >= 0 && speed <= 255){
          analogWrite(pwm, speed);
          OldSpeed = NewSpeed;
        }
      }
  }

  // Quick function for alternating the motor
  void debug(){
    CounterClockwise(255);
    delay(2000);
    Clockwise(255);
    delay(2000);
  }
};
#endif
