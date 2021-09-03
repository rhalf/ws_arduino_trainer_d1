#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);

uint8_t ADDRESS = 0;
uint32_t duration = 10;

uint8_t RGB[3] = {9, 10, 11};

void setup() {
  Serial.begin(9600);

  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);

}


void run() {
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 255);
  count(1, 7);

  analogWrite(9, 0);
  analogWrite(10, 192);
  analogWrite(11, 64);
  count(1, 3);

  analogWrite(9, 0);
  analogWrite(10, 255);
  analogWrite(11, 0);
  count(1, 10);
}

void count( uint8_t row, uint8_t number) {
  for (uint8_t count = number; count > 0; count--) {
    show(row, count);
    delay(1000);
  }
}

void show( uint8_t row, uint8_t number) {
  uint8_t first = number % 10;
  uint8_t Second = (number / 10) % 10;
  lc.setDigit(ADDRESS, row, Second, false);
  lc.setDigit(ADDRESS, row - 1, first, true);
}

void loop() {
  run();
}
