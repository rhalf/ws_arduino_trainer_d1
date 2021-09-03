#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);

uint8_t ADDRESS = 0;
uint32_t duration = 10;

uint8_t combination[4] = {0, 0, 0, 0};
uint8_t randNumber = 0, randMax = 49;

uint8_t BUTTON = 4;
void setup() {
  randomSeed(analogRead(A6));
  Serial.begin(9600);

  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);

  pinMode(BUTTON, INPUT_PULLUP);
}


void draw() {
  randNumber = random(randMax);
  count(1, randNumber);
  Serial.println(randNumber);


  randNumber = random(randMax);
  count(3, randNumber);
  Serial.println(randNumber);


  randNumber = random(randMax);
  count(5, randNumber);
  Serial.println(randNumber);


  randNumber = random(randMax);
  count(7, randNumber);
  Serial.println(randNumber);
}
void count( uint8_t row, uint8_t number) {
  for (uint8_t count = 0; count <= number; count++) {
    show(row, count);
    delay(10);
  }
}

void show( uint8_t row, uint8_t number) {
  uint8_t first = number % 10;
  uint8_t Second = (number / 10) % 10;
  lc.setDigit(ADDRESS, row, Second, false);
  lc.setDigit(ADDRESS, row - 1, first, true);
}

void loop() {
  if (digitalRead(BUTTON) == LOW) draw();
}
