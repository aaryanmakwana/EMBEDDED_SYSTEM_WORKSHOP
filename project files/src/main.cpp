#include "arduino.h"

#define BIT_0 3
#define BIT_1 5
#define BIT_2 7
#define BIT_3 9
#define BTTN 2
#define ASSIGNED_DELAY 500

byte i=0;
volatile int timer_on=0;
unsigned long delayedMillis;

void state_change(){
  timer_on++;
}

void setup(){
  pinMode(BIT_0,OUTPUT);
  pinMode(BIT_1,OUTPUT);
  pinMode(BIT_2,OUTPUT);
  pinMode(BIT_3,OUTPUT);
  pinMode(BTTN,INPUT);
  attachInterrupt(digitalPinToInterrupt(BTTN), state_change, RISING);

  delayedMillis = millis();

}


void led_write(int i){
  digitalWrite(BIT_0,i%2);
  digitalWrite(BIT_1,(i&2) == 2);
  digitalWrite(BIT_2,(i&4) == 4);
  digitalWrite(BIT_3,(i&8) == 8);
}

void loop(){

  i = i%16;


  if( (millis()-delayedMillis) >= ASSIGNED_DELAY){
    delayedMillis = millis();
    if(timer_on%3==1){
      i++;
    }
  }

  if(timer_on%3==0){
    i=0;
  }

  led_write(i);
}
