#include "application.h"

bool motorRun = false; /* controls if the motor runs forward */
bool motorStop = false; /* controls if the motor is stopped */
bool motorBack = false; /* controls if the motor runs backwards */
bool isMovingLeft = false; /* controls is servo moves left*/
bool isMovingRight = false; /* controls is servo moves right*/
bool isDecrementingLeft = false; /* controls is servo is adjusting position form left */
bool isDecrementingRight = false; /* controls if servo is adjusting position from right*/
int counter = 90; /* updates the angle for ServoMotor */

/* increments counter, adjusted the position of the motor*/
void incCounter(ServoMotor *servoMotor, int _counter);
/* decrements counter, adjusted the position of the motor*/
void decCounter(ServoMotor *servoMotor, int _counter);

void run(Bluetooth *bluetooth, Motor *motor, ServoMotor *servoMotor) {
  Serial.print(counter);
  Serial.print("\n");
  switch (bluetooth->getValue()) {
    case 0: /* Stop the motor */
      motorStop = true;
      motorRun = false;
      motorBack = false;
      break;
    case 1 : /* Move forward */
      motorStop = false;
      motorRun = true;
      motorBack = false;
      break;
    case 2: /* Move backwards */
      motorStop = false;
      motorRun = false;
      motorBack = true;
      break;
    case 3: /* Turn left */
      if (counter >= 90 && counter < 180) {
        Serial.print("In 3. \n");
        isMovingLeft = true;
        isDecrementingLeft = false;
        isMovingRight = false;
        isDecrementingRight = false;
      }
      break;
    case 13: /* Come back to initial position */
      if (counter > 90 && counter <= 180) {
        Serial.print("In 13. \n");
        isMovingLeft = false;
        isDecrementingLeft = true;
        isMovingRight = false;
        isDecrementingRight = false;
      }
      break;
    case 4: /* Turn right */
      if (counter >0 && counter <= 90) {
        Serial.print("In 4. \n");
        isMovingLeft = false;
        isDecrementingLeft = false;
        isMovingRight = true;
        isDecrementingRight = false;
      }
      break;
    case 14: /* Come back to the initial position */
      if (counter >=0 && counter < 90) {
        Serial.print("In 14. \n");
        isMovingLeft = false;
        isDecrementingLeft = false;
        isMovingRight = false;
        isDecrementingRight = true;
      }
      break;
    default:
      Serial.print("Poyavilosi huinea\n");
  }

  /* check if the servoMotor has to move left, move right
      or adjust its position from where it was turned */
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

  /* Check if the back motor runs front, back or is stopped. */
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
