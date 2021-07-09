#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);

uint8_t ADDRESS = 0;
uint32_t duration = 400;
uint32_t counter = 0;

void setup() {
  lc.shutdown(ADDRESS, false);
  lc.setIntensity(ADDRESS, 4);
  lc.clearDisplay(0);
}

void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[8] = {B00000000, B00100010, B00100010, B00111110, B00100010, B00100010, B00011100, B00000000};
  byte r[8] = {B00000000, B00100010, B00100010, B00011110, B00100010, B00100010, B00011110, B00000000};
  byte d[8] = {B00000000, B00011110, B00100010, B00100010, B00100010, B00100010, B00011110, B00000000};
  byte u[8] = {B00000000, B00011100, B00100010, B00100010, B00100010, B00100010, B00100010, B00000000};
  byte i[8] = {B00000000, B00001000, B00001000, B00001000, B00001000, B00001000, B00001000, B00000000};
  byte n[8] = {B00000000, B00100010, B00100010, B00110010, B00101010, B00100110, B00100010, B00000000};
  byte o[8] = {B00000000, B00011100, B00100010, B00100010, B00100010, B00100010, B00011100, B00000000};

  /* now display them one by one with a small delay */
  lc.setRow(ADDRESS, 0, a[0]);
  lc.setRow(ADDRESS, 1, a[1]);
  lc.setRow(ADDRESS, 2, a[2]);
  lc.setRow(ADDRESS, 3, a[3]);
  lc.setRow(ADDRESS, 4, a[4]);
  lc.setRow(ADDRESS, 5, a[5]);
  lc.setRow(ADDRESS, 6, a[6]);
  lc.setRow(ADDRESS, 7, a[7]);
  delay(duration);
  lc.setRow(ADDRESS, 0, r[0]);
  lc.setRow(ADDRESS, 1, r[1]);
  lc.setRow(ADDRESS, 2, r[2]);
  lc.setRow(ADDRESS, 3, r[3]);
  lc.setRow(ADDRESS, 4, r[4]);
  lc.setRow(ADDRESS, 5, r[5]);
  lc.setRow(ADDRESS, 6, r[6]);
  lc.setRow(ADDRESS, 7, r[7]);
  delay(duration);
  lc.setRow(ADDRESS, 0, d[0]);
  lc.setRow(ADDRESS, 1, d[1]);
  lc.setRow(ADDRESS, 2, d[2]);
  lc.setRow(ADDRESS, 3, d[3]);
  lc.setRow(ADDRESS, 4, d[4]);
  lc.setRow(ADDRESS, 5, d[5]);
  lc.setRow(ADDRESS, 6, d[6]);
  lc.setRow(ADDRESS, 7, d[7]);
  delay(duration);
  lc.setRow(ADDRESS, 0, u[0]);
  lc.setRow(ADDRESS, 1, u[1]);
  lc.setRow(ADDRESS, 2, u[2]);
  lc.setRow(ADDRESS, 3, u[3]);
  lc.setRow(ADDRESS, 4, u[4]);
  lc.setRow(ADDRESS, 5, u[5]);
  lc.setRow(ADDRESS, 6, u[6]);
  lc.setRow(ADDRESS, 7, u[7]);
  delay(duration);
  lc.setRow(ADDRESS, 0, i[0]);
  lc.setRow(ADDRESS, 1, i[1]);
  lc.setRow(ADDRESS, 2, i[2]);
  lc.setRow(ADDRESS, 3, i[3]);
  lc.setRow(ADDRESS, 4, i[4]);
  lc.setRow(ADDRESS, 5, i[5]);
  lc.setRow(ADDRESS, 6, i[6]);
  lc.setRow(ADDRESS, 7, i[7]);
  delay(duration);
  lc.setRow(ADDRESS, 0, n[0]);
  lc.setRow(ADDRESS, 1, n[1]);
  lc.setRow(ADDRESS, 2, n[2]);
  lc.setRow(ADDRESS, 3, n[3]);
  lc.setRow(ADDRESS, 4, n[4]);
  lc.setRow(ADDRESS, 5, n[5]);
  lc.setRow(ADDRESS, 6, n[6]);
  lc.setRow(ADDRESS, 7, n[7]);
  delay(duration);
  lc.setRow(ADDRESS, 0, o[0]);
  lc.setRow(ADDRESS, 1, o[1]);
  lc.setRow(ADDRESS, 2, o[2]);
  lc.setRow(ADDRESS, 3, o[3]);
  lc.setRow(ADDRESS, 4, o[4]);
  lc.setRow(ADDRESS, 5, o[5]);
  lc.setRow(ADDRESS, 6, o[6]);
  lc.setRow(ADDRESS, 7, o[7]);
  delay(duration);
  lc.clearDisplay(0);
}


void single() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      delay(duration/8);
      lc.setLed(ADDRESS, row, col, true);
      delay(duration/8);
    }
  }
}

void loop() {
  writeArduinoOnMatrix();
  single();
}
