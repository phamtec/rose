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
