#include "petal.hpp"

void Petal::init() {
  _servo.attach(_pin);
  _servo.write(_startangle);
}

void Petal::start() {
  if (!_running) {
    _curangle = _startangle;
    _running = true;
    _up = true;
  }
}

void Petal::service(unsigned long deltams) {
  
  if (_running) {
    if (deltams > 0) {
      double delta = (double)deltams / msPerDegree;
      if (_up) {
        _curangle += delta;
        if (_curangle >= _endangle) {
          _up = false;
        }
      }
      else {
        _curangle -= delta;
        if (_curangle <= _startangle) {
          _running = false;
        }
      }
      _servo.write((int)_curangle);
    }
  }
}
