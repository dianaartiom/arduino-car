#include "Arduino.h"
#include "Servo.h"
#include "setup.h"

Servo servoMotor;

void setup() {
  servoMotor.attach(SERVO_MOTOR_PWM_PIN);
  servoMotor.write(180);
  Serial.begin(9600);
}

void loop() {
  delay(500);
  Serial.println("Yeee it is working...");
}
