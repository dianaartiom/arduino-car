#include "ServoMotor.h"

ServoMotor::ServoMotor(int pwm) {
  this->_pwm = pwm;
}

void ServoMotor::setup() {
  this->servoMotor.attach(SERVO_MOTOR_PWM_PIN);
  this->servoMotor.write(180);
  return;
}

void ServoMotor::update(int angle) {
  this->servoMotor.write(angle);
}
