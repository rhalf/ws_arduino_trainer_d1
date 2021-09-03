#include "LedControl.h"
uint8_t CLK = A1, DT = A3, CS = A2, CHIP = 1;
LedControl lc = LedControl(DT, CLK, CS, CHIP);

uint8_t ADDRESS = 0;
uint32_t duration = 10;


uint8_t score = 0;

uint8_t BUTTON0 = 4;
uint8_t BUTTON1 = 3;
uint8_t BUTTON2 = 2;

void setup() {
  randomSeed(analogRead(A6));
  Serial.begin(9600);

  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);

  pinMode(BUTTON0, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
}


void count( uint8_t row, uint8_t number) {
  
  for (uint8_t count = score; count <= (score + number); count++) {
    show(row, count);
    delay(250);
  }
  score += number;
}

void show( uint8_t row, uint8_t number) {
  uint8_t first = number % 10;
  uint8_t Second = (number / 10) % 10;
  lc.setDigit(ADDRESS, row, Second, false);
  lc.setDigit(ADDRESS, row - 1, first, true);
}

void loop() {
  if (digitalRead(BUTTON0) == LOW) {
   
    count(1, 1);
  }
  if (digitalRead(BUTTON1) == LOW) {
    
    count(1, 2);
  }
  if (digitalRead(BUTTON2) == LOW) {
   
    count(1, 3);
  }
}
