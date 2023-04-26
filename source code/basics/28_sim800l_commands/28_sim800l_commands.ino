#include <SoftwareSerial.h>
SoftwareSerial gsm(8, 7);  // RX = 8, TX = 7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gsm.begin(9600);
  //check if module is ready
  command("AT");
  //set module set to full functionality
  command("AT+CFUN=1");
  //set module to verbose
  command("AT+CMEE=2");
  //check if sim is ready
  command("AT+CPIN?");
  //get sim number
  //command("AT+CCID?");
  //check if registered to network
  command("AT+CREG?");
  //check if signal
  command("AT+CSQ");
  //check imei
  command("AT+CGSN");
  //check manufacturing
  command("AT+CGMI");
  //check model
  command("AT+CGMM");
  //check revision
  command("AT+CGMR");
}
void command(String command) {
  // "\r\n" means Carriage return and Newline
  gsm.print(command + "\r\n");
  //Serves as timeout
  for (uint8_t count = 0; count < 100; count++) {
    delay(10);
    while (gsm.available())
      Serial.write(gsm.read());
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
