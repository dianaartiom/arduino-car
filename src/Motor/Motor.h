#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "Servo.h"
#include "setup.h"

class Motor {

private:
  Servo servoMotor;
  char _pin1;
  char _pin2;
  int _pwm;

public:
  Motor();
  Motor(char pin1, char pin2, int pwm);
  void setup();
  void run(int pwm, char direction);
  ~Motor();
};

#endif
