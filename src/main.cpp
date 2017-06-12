#include "Arduino.h"
#include "Servo.h"
#include "setup.h"

Servo servoMotor;
char data = 0;

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

  // Temp code for checking bluetooth
  // Start ===========================
  
  if(Serial.available() > 0)      // Send data only when you receive data:
  {
     data = Serial.read();        //Read the incoming data & store into data
     Serial.print(data);          //Print Value inside data in Serial monitor
     Serial.print("\n");
     if(data == '1')              // Checks whether value of data is equal to 1
        digitalWrite(13, HIGH);   //If value is 1 then LED turns ON
     else if(data == '0')         //  Checks whether value of data is equal to 0
        digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
  }

  // End =============================

  delay(300);
  Serial.println("Yeee it is working...");
}
