#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include "Arduino.h"
#include "Servo.h"
#include "setup.h"

class ServoMotor {

private:
  Servo servoMotor;
  int _pwm;

public:
  ServoMotor();
  ServoMotor(int pwm);
  void setup();
  void update(int);
  ~ServoMotor();
};

#endif
