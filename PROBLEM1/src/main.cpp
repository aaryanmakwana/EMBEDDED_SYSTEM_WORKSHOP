#include "arduino.h"

#if def PULL_UP
#define ON 0
#define OFF 1
#endif

#if def PULL_DOWN
#define ON 1
#define OFF 0
#endif

void setup(){
  pinMode(5,INPUT);
  pinMode(4,OUTPUT);
}

void loop(){
  if (digitalRead(5)==ON){
    digitalRead(4,HIGH);
  }else {
    digitalRead(4.LOW);
  }
}