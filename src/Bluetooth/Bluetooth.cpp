#include "Bluetooth.h"

Bluetooth::Bluetooth(char rx, char tx) {
  this->_rx = rx;
  this->_tx = tx;
}

void Bluetooth::read(char data) {
  
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
  return;
}
