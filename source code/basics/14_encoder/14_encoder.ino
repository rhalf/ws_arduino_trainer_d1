#include <Encoder.h>
uint8_t const DT = 2, CLK = 3, SW= 4;

Encoder encoder(DT, CLK);
int8_t data  = -128;

void setup() {
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int8_t newData = encoder.read();
  if (newData != data) {
    data = newData;
    Serial.println(newData);
  }
  if(digitalRead(SW) == LOW) 
    Serial.println("SW is pressed");
}
