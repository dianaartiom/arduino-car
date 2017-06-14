#include "ServoMotor.h"

ServoMotor::ServoMotor(int pwm, int value) {
  this->_pwm = pwm;
  this->_value = value;
}

void ServoMotor::setup(int value) {
  this->servoMotor.attach(SERVO_MOTOR_PWM_PIN);
  this->servoMotor.write(value);
  return;
}

void ServoMotor::update(int angle) {
  this->servoMotor.write(angle);
}

void ServoMotor::setValue(int value) {
  this->_value = value;
  return;
}

int ServoMotor::getValue() {
  return this->_value;
}
