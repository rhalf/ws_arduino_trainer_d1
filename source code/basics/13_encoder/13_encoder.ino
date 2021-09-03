#include <Encoder.h>
uint8_t const DT = 2, CLK = 3, SW= 4;

Encoder encoder(DT, CLK);
int8_t oldP  = -128;

void setup() {
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  uint8_t newP = encoder.read();
  if (newP != oldP) {
    oldP = newP;
    Serial.println(newP);
  }
  if(digitalRead(SW) == LOW) 
    Serial.println("SW is pressed");
}
