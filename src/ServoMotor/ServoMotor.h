#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include "Arduino.h"
#include "Servo.h"
#include "setup.h"

class ServoMotor {

private:
  Servo servoMotor;
  int _pwmPin;

public:
  ServoMotor();
  ServoMotor(int pwmPin);
  void setup(int value);
  void update(int);
  ~ServoMotor();
};

#endif
