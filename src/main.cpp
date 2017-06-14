#include "Arduino.h"

#include "Bluetooth/Bluetooth.h"
#include "Motor/Motor.h"
#include "ServoMotor/ServoMotor.h"
#include "application.h"

int data;
Bluetooth *bluetooth = new Bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);
Motor  *motor = new Motor(MOTOR_PIN_1, MOTOR_PIN_2, PWM_PIN);
ServoMotor *servoMotor = new ServoMotor(SERVO_MOTOR_PWM_PIN, 90);
static int rotateServo = 10;
static int anglePosition = 50;

void setup() {
  motor->setup();
  servoMotor->setup(50);
  pinMode(LED_TMP, OUTPUT); // Temporal led for testing bluetooth
  Serial.begin(9600);
}

void loop() {
  /* Running back motor */
  // motor->run(50, 1);

  /* Running servo motor */
  // servoMotor->update(20);

  /* Reading bluetooth data */
  bluetooth->read(data);

  run(bluetooth, motor, servoMotor);

  delay(1000);
  // Serial.println("Yeee it is working...");
}
