#include <SoftwareSerial.h>
SoftwareSerial gsm(8, 7);  //RX = 8, TX = 7
uint8_t LEDS[] = { 9, 10, 11 };

void command(String command) {
  delay(100);
  gsm.print(command + "\r\n");
}

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);

  command("AT");
  command("AT+CMGF=1");          //Configuring TEXT mode
  command("AT+CNMI=1,2,0,0,0");  //Send incoming messages to terminal
}

void loop() {
  if (gsm.available()) {
    String message = gsm.readStringUntil('\n');
    
    message.trim();

    if (message.equals("LED_ON")) {
      analogWrite(LEDS[0], 255);
    }
    if (message.equals("LED_OFF")) {
      analogWrite(LEDS[0], 0);
    }
    Serial.println(message);
  }

  if (Serial.available())
    gsm.write(Serial.read());
}
