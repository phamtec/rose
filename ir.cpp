#include "ir.hpp"

void IR::init() {
  _recv.enableIRIn(); // Start the receiver
  _recv.blink13(true);
}

int IR::waitForInput(unsigned long time) {
  decode_results results;
  if (_recv.decode(&results)) {
    int petal = -1;
    if (results.decode_type == 1) {
      switch (results.value) {
      case 0x229A:
        petal = 0;
        break;
        
      case 0x229B:
        petal = 1;
        break;
        
      case 0x229C:
        petal = 2;
        break;
        
      case 0x229D:
        petal = 3;
        break;
        
      case 0x229E:
        petal = 4;
        break;
        
      case 0x229F:
        petal = 5;
        break;

      default:
        break;
      }
    }
    _recv.resume();
    return petal;
  }
  return -1;
}
