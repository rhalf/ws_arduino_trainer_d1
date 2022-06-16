#include<SoftwareSerial.h>
uint8_t RX = 8, TX = 7;
SoftwareSerial bluetooth(RX, TX);
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  //check if module is ready
  sendCommand("AT");
  //set module name
  sendCommand("AT+NAME=HC05_XX"); //XX is the number of your arduino board box
  //check name
  sendCommand("AT+NAME?");
}
void sendCommand(String command) {
  bluetooth.print(command + "\r\n");
  for (uint8_t count = 0; count < 100; count++) {
    delay(10);
    while (bluetooth.available()) 
      Serial.write(bluetooth.read());
  };
  delay(100);
}
void loop() {
  if (bluetooth.available()) 
    Serial.write(bluetooth.read());
  if (Serial.available()) 
    bluetooth.write(Serial.read());
}
