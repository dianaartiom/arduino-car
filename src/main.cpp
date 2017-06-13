#include "Arduino.h"


#include "Bluetooth/Bluetooth.h"
#include "Motor/Motor.h"

static char data = 0;
Bluetooth *bluetooth = new Bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);
Motor  *motor = new Motor(MOTOR_PIN_1, MOTOR_PIN_2, PWM_PIN);

void setup() {
  motor->setup();
  pinMode(LED_TMP, OUTPUT); // Temporal led for testing bluetooth
  Serial.begin(9600);
}

void loop() {
  /* Running back motor */
  motor->run(50, '1');

  /* Reading bluetooth data */
  bluetooth->read(data);

  delay(300);
  Serial.println("Yeee it is working...");
}
