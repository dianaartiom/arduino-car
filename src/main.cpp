#include "Arduino.h"

#include "Bluetooth/Bluetooth.h"
#include "Motor/Motor.h"
#include "ServoMotor/ServoMotor.h"

static char data = 0;
Bluetooth *bluetooth = new Bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);
Motor  *motor = new Motor(MOTOR_PIN_1, MOTOR_PIN_2, PWM_PIN);
ServoMotor *servoMotor = new ServoMotor(180);

void setup() {
  motor->setup();
  servoMotor->setup();
  pinMode(LED_TMP, OUTPUT); // Temporal led for testing bluetooth
  Serial.begin(9600);
}

void loop() {
  /* Running back motor */
  motor->run(50, '1');

  /* Running servo motor */
  servoMotor->update(180);

  /* Reading bluetooth data */
  bluetooth->read(data);

  delay(300);
  Serial.println("Yeee it is working...");
}
