#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);

uint8_t ADDRESS = 0;
uint32_t duration = 400;
uint32_t counter = 0;

void setup() {
  lc.shutdown(ADDRESS, false);
  lc.clearDisplay(0);
}

void loop() {

}
