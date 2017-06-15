#include "ServoMotor.h"

ServoMotor::ServoMotor(int pwmPin) {
  this->_pwmPin = pwmPin;
}

void ServoMotor::setup(int value) {
  this->servoMotor.attach(SERVO_MOTOR_PWM_PIN);
  this->servoMotor.write(value);
  return;
}

void ServoMotor::update(int angle) {
  this->servoMotor.write(angle);
}
