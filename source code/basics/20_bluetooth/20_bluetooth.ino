#include<SoftwareSerial.h>
SoftwareSerial bluetooth(8, 7); //RX = 8, TX = 7;
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop() {
  if (bluetooth.available()) 
    Serial.write(bluetooth.read());
  if (Serial.available())
    bluetooth.write(Serial.read());
}
