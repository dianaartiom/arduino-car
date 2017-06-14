#ifndef _BLUETOOTH_H
#define  _BLUETOOTH_H

#include "Arduino.h"

class Bluetooth {

private:
  char _rx;
  char _tx;
  int _value;

public:
  Bluetooth(char rx, char tx);
  void read(int data);
  ~Bluetooth();
  int getValue();
};

#endif
