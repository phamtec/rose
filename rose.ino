#include <Servo.h>

#include "petal.hpp"
#include "term.hpp"
#include "ir.hpp"

const int ledPin =  13;

Petal *gPetals[] = { 
  new Petal(4, 100, 140), // pin, start angle, end angle
  new Petal(5, 100, 140), 
  new Petal(6, 100, 140), 
  new Petal(7, 100, 140), 
  new Petal(8, 100, 140), 
  new Petal(9, 100, 140) };
  
IR gIR(11); // IR on pin 11
TERM gTERM;

unsigned long gLastTime;

void setup() {
  pinMode(ledPin, OUTPUT);
  for (int i=0; i<(sizeof(gPetals)/sizeof(Petal *)); i++) {
    gPetals[i]->init();
  }
  gIR.init();
  gTERM.init();
}

void loop() {
  unsigned long curtime = millis();
  int servo = gIR.waitForInput(curtime);
//  int servo = gTERM.waitForInput(curtime);
  if (servo >= 0) {
    gPetals[servo]->start();
  }
  for (int i=0; i<(sizeof(gPetals)/sizeof(Petal *)); i++) {
    gPetals[i]->service(curtime - gLastTime);
  }
  gLastTime = curtime;
}

void TERM::init() {
  Serial.begin(9600); 
}

int TERM::waitForInput(unsigned long time) {
  if (Serial.available()) {
    int incomingByte =  Serial.read();
    int servoNum = (incomingByte - '1');
    if (servoNum >= 0 && servoNum <= (sizeof(gPetals)/sizeof(Petal *))) {
      return servoNum;
    }
  }
  return -1;
}

