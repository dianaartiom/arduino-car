#include "application.h"

bool motorRun = false;
bool motorStop = false;
bool motorBack = false;
bool isMovingLeft = false;
bool isMovingRight = false;
bool isDecrementingLeft = false;
bool isDecrementingRight = false;
void incCounter(ServoMotor *servoMotor, int _counter);
void decCounter(ServoMotor *servoMotor, int _counter);

int counter = 90; /* updates the angle for ServoMotor */

void run(Bluetooth *bluetooth, Motor *motor, ServoMotor *servoMotor) {
  Serial.print(counter);
  Serial.print("\n");
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
      if (counter >= 90 && counter < 180) {
        Serial.print("In 3. \n");
        isMovingLeft = true;
        isDecrementingLeft = false;
        isMovingRight = false;
        isDecrementingRight = false;
      }
      break;
    case 13:
      if (counter > 90 && counter <= 180) {
        Serial.print("In 13. \n");
        isMovingLeft = false;
        isDecrementingLeft = true;
        isMovingRight = false;
        isDecrementingRight = false;
      }
      break;
    case 4:
      if (counter >0 && counter <= 90) {
        Serial.print("In 4. \n");
        isMovingLeft = false;
        isDecrementingLeft = false;
        isMovingRight = true;
        isDecrementingRight = false;
      }
      break;
    case 14:
    if (counter >=0 && counter < 90) {
      Serial.print("In 14. \n");
      isMovingLeft = false;
      isDecrementingLeft = false;
      isMovingRight = false;
      isDecrementingRight = true;
    }
    default:
      Serial.print("Poyavilosi huinea\n");
  }

  if (isMovingLeft) {
    if (counter >= 90 && counter < 180) {
      incCounter(servoMotor,counter);
    }
  } else if (isMovingRight) {
    if (counter >0 && counter <= 90) {
      decCounter(servoMotor, counter);
    }
  } else if (isDecrementingLeft) {
    if (counter > 90 && counter <= 180) {
      decCounter(servoMotor, counter);
    }
  } else if (isDecrementingRight) {
    if (counter >=0 && counter < 90) {
      incCounter(servoMotor, counter);
    }
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

void decCounter(ServoMotor *servoMotor, int _counter) {
  counter -= 9;
  servoMotor->update(_counter);
  Serial.print("Servo decrementing right. Value: ");
  Serial.print(counter);
  Serial.print("\n");
}

void incCounter(ServoMotor *servoMotor, int _counter) {
  counter += 9;
  servoMotor->update(_counter);
  Serial.print("Servo decrementing right. Value: ");
  Serial.print(counter);
  Serial.print("\n");
}
