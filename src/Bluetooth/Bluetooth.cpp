#include "Bluetooth.h"

Bluetooth::Bluetooth(char rx, char tx) {
  this->_rx = rx;
  this->_tx = tx;
  this->_value = 0;
}

void Bluetooth::read(int data) {

  if(Serial.available() > 0) {      // Send data only when you receive data:

     data = Serial.read();        //Read the incoming data & store into data
     Serial.print("Command: ");
     Serial.print(data);          //Print Value inside data in Serial monitor
     Serial.print("\n");
     this->_value = data;
  }
  return;
}

int Bluetooth::getValue() {
  return this->_value;
}
