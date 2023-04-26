#include<SoftwareSerial.h>
SoftwareSerial gsm(RX, TX); //RX = 8, TX = 7;

void confirm() {
  delay(100);
  gsm.write(26);
}

void command(String command) {
  delay(100);
  gsm.print(command + "\r\n");
}

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  
  command("AT"); //chech if device is ready
  command("AT+CMGF=1"); //set gsm to text mode
  command("AT+CMGS=\"+639xxxxxxxxx\""); //set to send sms message
  command("Hello!"); // sms message
  confirm(); //confirm message
}

void loop() {
  if (gsm.available()) 
    Serial.write(gsm.read());
  if (Serial.available())
    gsm.write(Serial.read());
}
