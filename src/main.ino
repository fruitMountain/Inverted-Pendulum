#include "Accelerometer.h"
#include "Motor.h"
#include "Filter.h"

Accelerometer acc(A0, A1, A2);
Motor motor(3,8,9,10);
Filter filter(.5);

int test = 0;

void setup(){
  Serial.begin(9600);
  while (! Serial); //Wait for serial to begin
  motor.startup(); // Calls a function to set motor pins
}

void loop(){
  float temp = acc.GetTheta() * (255. / 3.14);
  int theta = static_cast<int>(temp);
  theta = 2 * theta;
  if(theta > 255){
    theta = 255;
  }
  if(theta < -255){
    theta = -255;
  }
  Serial.print(theta);

  if(theta > 0){
    motor.Clockwise(2*theta);
    //delay(100);
    Serial.println("c");
  } else if(theta < 0){
    motor.CounterClockwise(-2*theta);
    //delay(100);
    Serial.println("cc");
  } else {
    motor.Stop();
    Serial.println();
    }

  }
