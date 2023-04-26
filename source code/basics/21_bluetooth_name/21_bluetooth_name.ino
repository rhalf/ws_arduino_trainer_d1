#include<SoftwareSerial.h>
SoftwareSerial bluetooth(8, 7); //RX = 8, TX = 7;

void command(String command) {
  bluetooth.print(command + "\r\n");
  delay(100);
}
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  command("AT"); //check if module is ready
  command("AT+NAME=HC05_46"); //set module name
  command("AT+NAME?"); //check name
}
void loop() {
  if (bluetooth.available()) 
    Serial.write(bluetooth.read());
  if (Serial.available()) 
    bluetooth.write(Serial.read());
}
