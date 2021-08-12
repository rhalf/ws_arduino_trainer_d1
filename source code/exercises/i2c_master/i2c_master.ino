// Arduino master sketch
#include <Wire.h>

uint8_t address = 8;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(address);
  Wire.write("Hi humans!\n");
  Wire.endTransmission();

  delay(1000);

  Wire.requestFrom(address, 14);
  while (Wire.available()) {
    char char1 = Wire.read();
    Serial.print(char1);
  }

  delay(1000);
}
