#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include "Arduino.h"
#include "Servo.h"
#include "setup.h"

class ServoMotor {

private:
  Servo servoMotor;
  int _pwm;
  int _value;

public:
  ServoMotor();
  ServoMotor(int pwm, int value);
  void setup(int value);
  void update(int);
  int getValue();
  void setValue(int);
  ~ServoMotor();
};

#endif
