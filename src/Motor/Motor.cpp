#include "Motor.h"

Motor::Motor(char pin1, char pin2, int pwm) {
  this->_pin1 = pin1;
  this->_pin2 = pin2;
  this->_pwm = pwm;
}

void Motor::setup() {
  pinMode(this->_pin1, OUTPUT); //Initiates Motor Channel A pin
  pinMode(this->_pin2, OUTPUT); //Initiates Brake Channel A pin
  Serial.begin(9600);
  return;
}

void Motor::run(int pwm, char direction) {
  switch (direction) {
    case '1': /* Moves forward */
      digitalWrite(this->_pin1, HIGH); //Establishes forward direction of Channel A
      digitalWrite(this->_pin2, LOW);   //Disengage the Brake for Channel A
    case '0': /* Moves backwards */
      digitalWrite(this->_pin1, LOW); //Establishes forward direction of Channel A
      digitalWrite(this->_pin2, HIGH);   //Disengage the Brake for Channel A
    default: /* Moves forward */
    digitalWrite(this->_pin1, HIGH); //Establishes forward direction of Channel A
    digitalWrite(this->_pin2, LOW);   //Disengage the Brake for Channel A
  }
  analogWrite(this->_pwm, pwm);   //Spins the motor on Channel A at full speed
}
