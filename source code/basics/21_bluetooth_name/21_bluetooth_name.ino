#include<SoftwareSerial.h>
uint8_t RX = 8, TX = 7;
SoftwareSerial bluetooth(RX, TX);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);

  //check if module is ready
  sendCommand("AT");
  //set module name
  sendCommand("AT+NAME=HC05");
  //check name
  sendCommand("AT+NAME?");
}

void sendCommand(String command) {
  bluetooth.print(command + "\r\n");
  uint8_t count = 0;
  while (count < 100) {
    delay(10);
    while (bluetooth.available()) {
      Serial.write(bluetooth.read());
    }
    count++;
  };
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
}
