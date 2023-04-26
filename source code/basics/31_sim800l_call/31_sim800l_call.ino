#include <SoftwareSerial.h>
SoftwareSerial gsm(8, 7); //RX = 8, TX = 7;

void command(String command) {
  delay(100);
  gsm.print(command + "\r\n");
}

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);

  command("AT");
  command("AT+CSQ");
  command("ATD+639176088771;");  //make a call
  delay(15000);
  command("ATH");  //drop the call
}

void loop() {
  if (gsm.available())
    Serial.write(gsm.read());
  if (Serial.available())
    gsm.write(Serial.read());
}
