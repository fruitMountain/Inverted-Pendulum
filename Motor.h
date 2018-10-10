// Arduino
// Write to electric motor

#ifndef MOTOR_H //checks to see if this is defined
#define MOTOR_H //defines it if the check passes
// This prevents this header from being called twice on accident

#include <Arduino.h> //allows us to use analogRead

class Motor{
 public:
  // Define variables for pins:
  int In1, In2, pwm, stby;
  int NewSpeed, OldSpeed = 0;
  int speed;

  void startup(){
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
    pinMode(pwm, OUTPUT);
    pinMode(stby, OUTPUT);
    digitalWrite(stby, HIGH);
  };

  void Clockwise(int speed){
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);

    NewSpeed = speed;
    if (NewSpeed != OldSpeed){
      if (speed >= 0 && speed <= 255){
        analogWrite(pwm, speed);
      }
    }
  }
    void CounterClockwise(int speed){
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);

      NewSpeed = speed;
      if (NewSpeed != OldSpeed){
        if (speed >= 0 && speed <= 255){
          analogWrite(pwm, speed);
        }
      }
    }
};
#endif
