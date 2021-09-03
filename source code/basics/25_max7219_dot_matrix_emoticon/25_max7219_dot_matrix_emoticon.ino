#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);

uint8_t ADDRESS = 0;
uint32_t duration = 2000;
uint32_t counter = 0;

void setup() {
  lc.shutdown(ADDRESS, false);
  lc.setIntensity(ADDRESS, 4);
  lc.clearDisplay(0);
}

void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte image[8] = {B00111100, B01000010, B10011001, B10100101, B10000001, B10100101, B01000010, B00111100};

  /* now display them one by one with a small delay */
  lc.setRow(ADDRESS, 0, image[0]);
  lc.setRow(ADDRESS, 1, image[1]);
  lc.setRow(ADDRESS, 2, image[2]);
  lc.setRow(ADDRESS, 3, image[3]);
  lc.setRow(ADDRESS, 4, image[4]);
  lc.setRow(ADDRESS, 5, image[5]);
  lc.setRow(ADDRESS, 6, image[6]);
  lc.setRow(ADDRESS, 7, image[7]);
  delay(duration);
  lc.setRow(ADDRESS, 0, ~image[0]);
  lc.setRow(ADDRESS, 1, ~image[1]);
  lc.setRow(ADDRESS, 2, ~image[2]);
  lc.setRow(ADDRESS, 3, ~image[3]);
  lc.setRow(ADDRESS, 4, ~image[4]);
  lc.setRow(ADDRESS, 5, ~image[5]);
  lc.setRow(ADDRESS, 6, ~image[6]);
  lc.setRow(ADDRESS, 7, ~image[7]);
  delay(duration);
  lc.clearDisplay(0);
}


void single() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      delay(duration / 100);
      lc.setLed(ADDRESS, row, col, true);
      delay(duration / 100);
    }
  }
}

void loop() {
  writeArduinoOnMatrix();
  single();
}
