#include "Arduino.h"

#include "Bluetooth/Bluetooth.h"
#include "Motor/Motor.h"
#include "ServoMotor/ServoMotor.h"
#include "application.h"

int data; /* data to store value from the bluetooth */
Bluetooth *bluetooth = new Bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);
Motor  *motor = new Motor(MOTOR_PIN_1, MOTOR_PIN_2, PWM_PIN);
ServoMotor *servoMotor = new ServoMotor(SERVO_MOTOR_PWM_PIN);

void setup() {
  motor->setup();
  servoMotor->setup(90);
  Serial.begin(9600);
}

void loop() {

  /* Reading bluetooth data */
  bluetooth->read(data);

  /* Running the application */
  run(bluetooth, motor, servoMotor);

}
