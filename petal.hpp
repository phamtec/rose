/*
 * Petal
 * 
 * A single petal of the rose. init with a pin number where
 * the servo lives, a start and end angle of the servo.
 * 
 * When you want to start it going call "start()" and then in the
 * main loop call "service()" with the number of ms that have
 * elapsed since last time.
 * 
 * Author: Paul Hamilton
 * Date: 12 Dec 2016
 * 
 */
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
