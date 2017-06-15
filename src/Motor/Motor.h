#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "setup.h"

class Motor {

private:
  char _pin1;
  char _pin2;
  int _pwmPin;

public:
  Motor();
  Motor(char pin1, char pin2, int pwmPin);
  void setup();
  void run(int pwm);
  void back(int pwm);
  void stop();
  ~Motor();
};

#endif
