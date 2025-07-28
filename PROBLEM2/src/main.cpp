#include "arduino.h"
#include "Servo.h"

#define dt 300

Servo motor;

void setup(){
  motor.attach(3); //PWM pin of servo is connected to GPIO3
}

void loop(){
  motor.write(45);
  delay(dt);
  motor.write(0);
  delay(dt);
}