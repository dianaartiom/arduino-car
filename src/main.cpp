#include "Arduino.h"

#include "Bluetooth/Bluetooth.h"
#include "Motor/Motor.h"
#include "ServoMotor/ServoMotor.h"
#include "application.h"

int data;
Bluetooth *bluetooth = new Bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);
Motor  *motor = new Motor(MOTOR_PIN_1, MOTOR_PIN_2, PWM_PIN);
ServoMotor *servoMotor = new ServoMotor(SERVO_MOTOR_PWM_PIN, 0);
static int rotateServo = 10;
static int anglePosition = 50;

void setup() {
  motor->setup();
  servoMotor->setup(90);
  pinMode(LED_TMP, OUTPUT); // Temporal led for testing bluetooth
  Serial.begin(9600);
}

void loop() {

  /* Reading bluetooth data */
  bluetooth->read(data);

  run(bluetooth, motor, servoMotor);

}
