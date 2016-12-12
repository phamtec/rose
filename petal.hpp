#ifndef H_PETAL
#define H_PETAL

#include <Servo.h>

class Petal {
public:
  Petal(int pin, int startangle, int endangle) : _pin(pin), 
    _running(false), _startangle(startangle), _endangle(endangle) {}

  void init();
  void start();
  void service(unsigned long deltams);
  
private:
  Servo _servo;
  int _pin;
  bool _running;
  bool _up;
  int _startangle;
  int _endangle;
  double _curangle;
};

const double msPerDegree = 20.0; // overall speed

#endif // H_PETAL
