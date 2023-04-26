#include<SoftwareSerial.h>
SoftwareSerial gsm(8, 7); //RX = 8, TX = 7

void command(String command) {
  delay(100);
  gsm.print(command + "\r\n");
}

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);

  command("AT");
  command("AT+CMGF=1"); //Configuring TEXT mode
  command("AT+CNMI=1,2,0,0,0"); //Send incoming messages to terminal
}

void loop() {
  if (gsm.available()) 
    Serial.write(gsm.read());
  if (Serial.available()) 
    gsm.write(Serial.read());
}
