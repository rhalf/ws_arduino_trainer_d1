#include<SoftwareSerial.h>
uint8_t RX = 8, TX = 7;
SoftwareSerial gsm(RX, TX);

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);

  delay(100);
  gsm.print("AT\r\n");
  delay(100);
  gsm.print("AT+CMGF=1\r\n");
  delay(100);
  gsm.print("AT+CNMI=1,2,0,0,0\r\n");
  delay(100);
}

void loop() {
  if (gsm.available()) 
    Serial.write(gsm.read());
  if (Serial.available()) 
    gsm.write(Serial.read());
}
