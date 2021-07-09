#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);

uint8_t ADDRESS = 0;
uint32_t duration = 10;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);

  show();
}

void show() {
  lc.setChar(ADDRESS, 7, 'a', false);
  lc.setRow(ADDRESS, 6, 0x05);
  lc.setChar(ADDRESS, 5, 'd', false);
  lc.setRow(ADDRESS, 4, 0x1c);
  lc.setRow(ADDRESS, 3, B00010000);
  lc.setRow(ADDRESS, 2, 0x15);
  lc.setRow(ADDRESS, 1, 0x1D);
  lc.setDigit(ADDRESS, 0, 0x08, false);
}

void loop() {

}
