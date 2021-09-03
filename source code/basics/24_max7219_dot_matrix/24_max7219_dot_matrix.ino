#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);
uint8_t ADDRESS = 0;
uint32_t duration = 400, counter = 0;
void setup() {
  lc.shutdown(ADDRESS, false);
  lc.setIntensity(ADDRESS, 4);
  lc.clearDisplay(0);
}
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[8] = {
    B00000000, 
    B00100010, 
    B00100010, 
    B00111110, 
    B00100010, 
    B00100010, 
    B00011100, 
    B00000000};
  // byte r[8] = {B00000000, B00100010, B00100010, B00011110, B00100010, B00100010, B00011110, B00000000};
  // byte d[8] = {B00000000, B00011110, B00100010, B00100010, B00100010, B00100010, B00011110, B00000000};
  // byte u[8] = {B00000000, B00011100, B00100010, B00100010, B00100010, B00100010, B00100010, B00000000};
  // byte i[8] = {B00000000, B00001000, B00001000, B00001000, B00001000, B00001000, B00001000, B00000000};
  // byte n[8] = {B00000000, B00100010, B00100010, B00110010, B00101010, B00100110, B00100010, B00000000};
  // byte o[8] = {B00000000, B00011100, B00100010, B00100010, B00100010, B00100010, B00011100, B00000000};

  /* now display them one by one with a small delay */
  for (uint8_t i = 0; i < 8; i++)
    lc.setRow(ADDRESS, i, a[i]);
  delay(duration);
  lc.clearDisplay(0);
}
void single() {
  for (uint8_t row = 0; row < 8; row++) {
    for (uint8_t col = 0; col < 8; col++) {
      delay(duration / 8);
      lc.setLed(ADDRESS, row, col, true);
      delay(duration / 8);
    }
  }
}
void loop() {
  writeArduinoOnMatrix();
  single();
}
