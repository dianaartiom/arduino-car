#include "application.h"

bool motorRun = false;
bool motorStop = false;
bool motorBack = false;
int counter = 0; /* updates the angle for ServoMotor */

void run(Bluetooth *bluetooth, Motor *motor, ServoMotor *servoMotor) {
  switch (bluetooth->getValue()) {
    case 0:
      motorStop = true;
      motorRun = false;
      motorBack = false;
      break;
    case 1 :
      motorStop = false;
      motorRun = true;
      motorBack = false;
      break;
    case 2:
      motorStop = false;
      motorRun = false;
      motorBack = true;
      break;
    case 3:
      counter +=1;
      servoMotor->update(servoMotor->getValue() + counter);
      Serial.print("Servo running left. Value: ");
      Serial.print(servoMotor->getValue() + counter);
      Serial.print("\n");
      break;
    case 13:
      Serial.print("O intrat\n");
      while (counter >= 0) {
        counter--;
        servoMotor->update(servoMotor->getValue() + counter);
        Serial.print("Servo repositioning from left. Value: ");
        Serial.print(servoMotor->getValue() + counter);
        Serial.print("\n");
      }
      break;
    case 4:
      counter +=1;
      servoMotor->update(servoMotor->getValue() + counter);
      Serial.print("Servo running right. Value: ");
      Serial.print(servoMotor->getValue() + counter);
      Serial.print("\n");
      break;
    case 14:
      while (counter >= 0) {
        counter--;
        servoMotor->update(servoMotor->getValue() + counter);
        servoMotor->update(servoMotor->getValue() + counter);
        Serial.print("Servo repositioning from right. Value: ");
        Serial.print(servoMotor->getValue() + counter);
        Serial.print("\n");
      }
    default:
      Serial.print("Poyavilosi huinea\n");
  }

  if (motorStop) {
    motor->stop(); /* stops the car */
    Serial.print("Motor stopped. \n");
  } else if (motorBack) {
    motor->stop(); /* stops the car */
    motor->back(50);
    Serial.print("Motor running backwards. \n");
  } else if (motorRun) {
    motor->run(50); /* moves forward */
    Serial.print("Motor running forward. \n");
  }

  return;
}
