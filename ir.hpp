/*
 * IR
 * 
 * Interface to an IR port. It returns the number
 * of the rose petal to start.
 * 
 * Author: Paul Hamilton
 * Date: 12 Dec 2016
 * 
 */
#ifndef H_IR
#define H_IR

#include <IRremote.h>

class IR {
public:
  IR(int pin) : _recv(pin), _lastTime(0) {}

  void init();
  int waitForInput(unsigned long time);

private:
  IRrecv _recv;
  unsigned long _lastTime;
};

#endif // H_IR
