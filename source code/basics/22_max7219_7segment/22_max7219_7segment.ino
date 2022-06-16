#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);
uint8_t ADDRESS = 0;
uint32_t dura = 10, counter = 0;
void setup() {
  lc.shutdown(ADDRESS, false);
  lc.setIntensity(ADDRESS, 4);
  lc.clearDisplay(ADDRESS);
}
void show(uint32_t number) {
  for (uint8_t digit = 0; digit < 8; digit++) {
    float value = number / (pow(10, digit));
    uint8_t no = ((int)value) % 10;
    lc.setDigit(ADDRESS, digit, no, false);
  }
}
void loop() {
  counter++;
  show(counter);
  delay(dura);
}