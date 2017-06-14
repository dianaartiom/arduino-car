#ifndef APPLICATION_H
#define APPLICATION_H

#include "Arduino.h"
#include "Bluetooth/Bluetooth.h"
#include "Motor/Motor.h"
#include "ServoMotor/ServoMotor.h"

void run(Bluetooth *bluetooth, Motor *motor, ServoMotor *servoMotor);

#endif
