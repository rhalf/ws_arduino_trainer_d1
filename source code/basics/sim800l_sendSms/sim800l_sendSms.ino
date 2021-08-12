#include<SoftwareSerial.h>

uint8_t RX = 8, TX = 7;

SoftwareSerial gsm(RX, TX);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gsm.begin(9600);

  delay(100);
  gsm.print("AT\r\n");
  delay(100);
  gsm.print("AT+CMGF=1\r\n");
  delay(100);
  gsm.print("AT+CMGS=\"+09176088771\"\r\n");
  delay(100);
  gsm.print("Hello World from Dev Craze!\r\n");
  delay(100);
  gsm.write(26);
}




void loop() {
  // put your main code here, to run repeatedly:
  if (gsm.available()) {
    Serial.write(gsm.read());
  }
  if (Serial.available()) {
    gsm.write(Serial.read());
  }
}
