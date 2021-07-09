#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);

uint8_t ADDRESS = 0;
uint32_t duration = 10;
uint32_t counter = 0;


void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);

   show();
}

void show() {
  for (uint8_t index = 0; index < 8; index++) {
    float value = counter / (pow(10, index));
    uint8_t digit = ((int)value) % 10;
    lc.setDigit(ADDRESS, index, digit, false);
  }
}

void loop() {
 
  counter++;
  
  delay(duration);
}
