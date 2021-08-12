// Arduino slave sketch
#include <Wire.h>

uint8_t address = 8;

void setup() {
  Serial.begin(9600);
  Wire.begin(address);
  Wire.onReceive(onReceived);    // register an event handler for received data
  Wire.onRequest(onRequested);   // register an event handler for data requests
}

void loop() {

}

void onReceived(int length) {
  while (Wire.available()) {
    char char1 = Wire.read();
    Serial.print(char1);
  }
   Wire.write("Hello Aliens!\n");
}

void onRequested() {
  Wire.write(1);
}
