#include<SoftwareSerial.h>
uint8_t RX = 8, TX = 7;
SoftwareSerial gsm(RX, TX);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gsm.begin(9600);
  //check if module is ready
  sendCommand("AT");
  //set module set to full functionality
  sendCommand("AT+CFUN=1");
  //set module to verbose
  sendCommand("AT+CMEE=2");
  //check if sim is ready
  sendCommand("AT+CPIN?");
  //get sim number
  //sendCommand("AT+CCID?");
  //check if registered to network
  sendCommand("AT+CREG?");
  //check if signal
  sendCommand("AT+CSQ");
  //check imei
  sendCommand("AT+CGSN");
  //check manufacturing
  sendCommand("AT+CGMI");
  //check model
  sendCommand("AT+CGMM");
  //check revision
  sendCommand("AT+CGMR");
}
void sendCommand(String command) {
  // "\r\n" means Carriage return and Newline
  gsm.print(command + "\r\n");
  //Serves as timeout
  for(uint8_t count = 0; count < 100; count++) {
    delay(10);
    while (gsm.available()) {
      Serial.write(gsm.read());
    }
  };
  delay(250);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (gsm.available()) 
    Serial.write(gsm.read());
  if (Serial.available()) 
    gsm.write(Serial.read());
}
