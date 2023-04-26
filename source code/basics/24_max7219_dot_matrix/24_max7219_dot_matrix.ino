#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);
uint32_t ADDRESS = 0, dura = 400, counter = 0;
void setup() {
  lc.shutdown(ADDRESS, false);
  lc.setIntensity(ADDRESS, 4);
  lc.clearDisplay(ADDRESS);
}

void loop() {
  uint8_t a[8] = {
    B00000000,
    B00100010,
    B00100010,
    B00111110,
    B00100010,
    B00100010,
    B00011100,
    B00000000
  };
  // uint8_t r[8] = {B00000000, B00100010, B00100010, B00011110, B00100010, B00100010, B00011110, B00000000};
  // uint8_t d[8] = {B00000000, B00011110, B00100010, B00100010, B00100010, B00100010, B00011110, B00000000};
  // uint8_t u[8] = {B00000000, B00011100, B00100010, B00100010, B00100010, B00100010, B00100010, B00000000};
  // uint8_t i[8] = {B00000000, B00001000, B00001000, B00001000, B00001000, B00001000, B00001000, B00000000};
  // uint8_t n[8] = {B00000000, B00100010, B00100010, B00110010, B00101010, B00100110, B00100010, B00000000};
  // uint8_t o[8] = {B00000000, B00011100, B00100010, B00100010, B00100010, B00100010, B00011100, B00000000};

  /* now display them one by one with a small delay */
  for (uint8_t i = 0; i < 8; i++)
    lc.setRow(ADDRESS, i, a[i]);
  delay(dura);
  lc.clearDisplay(0);
}
