#ifndef _BLUETOOTH_H
#define  _BLUETOOTH_H

#include "Arduino.h"

class Bluetooth {

private:
  char _rx;
  char _tx;

public:
  Bluetooth(char rx, char tx);
  void read(char data);
  ~Bluetooth();
};

#endif
