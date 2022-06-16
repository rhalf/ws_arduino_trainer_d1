#include<SoftwareSerial.h>
uint8_t RX = 8, TX = 7;
SoftwareSerial gsm(RX, TX);
void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
}
void loop() {
  if (gsm.available()) 
    Serial.write(gsm.read());
  if (Serial.available())
    gsm.write(Serial.read());
}
