#include<SoftwareSerial.h>
uint8_t RX = 8, TX = 7;
SoftwareSerial gsm(RX, TX);
void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.print("AT\r\n");
  delay(100);
  gsm.print("AT+CSQ\r\n");
  delay(100);
  gsm.print("ATD+639705786311;\r\n");
  delay(15000);
  gsm.print("ATH\r\n");
  //delay(100)//
  //gsm.print("ATA\r\n"); answer call
  //delay(10000);
  //gsm.print("ATH\r\n"); drop call
}
void loop() {
  if (gsm.available()) 
    Serial.write(gsm.read());
  if (Serial.available())
    gsm.write(Serial.read());
}
