#include "Arduino.h"
#include "Servo.h"
#include "setup.h"
#include "Bluetooth/Bluetooth.h"

Servo servoMotor;
static char data = 0;
Bluetooth *bluetooth = new Bluetooth('0', '1');

void setup() {
  servoMotor.attach(SERVO_MOTOR_PWM_PIN);
  servoMotor.write(180);
  pinMode(MOTOR_PIN_1, OUTPUT); //Initiates Motor Channel A pin
  pinMode(MOTOR_PIN_2, OUTPUT); //Initiates Brake Channel A pin
  pinMode(LED_TMP, OUTPUT); // Temporal led for testing bluetooth
  Serial.begin(9600);
}

void loop() {
  digitalWrite(MOTOR_PIN_1, HIGH); //Establishes forward direction of Channel A
  digitalWrite(MOTOR_PIN_2, LOW);   //Disengage the Brake for Channel A
  analogWrite(PWM_PIN, 50);   //Spins the motor on Channel A at full speed

  /* Reading bluetooth data */
  bluetooth->read(data);

  delay(300);
  Serial.println("Yeee it is working...");
}

