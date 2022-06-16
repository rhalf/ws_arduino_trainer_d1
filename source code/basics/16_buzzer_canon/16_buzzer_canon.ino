#include"pitches.h"
uint8_t const BUZZER = A0;

uint16_t chords[] = {
  A6, FS6, G6,  A6, FS6, G6, A6,  A5,
  B5, CS6, D6,  E6, FS6, G6, FS6, D6,
  E6, FS6, FS5, G5, A5,  B5, A5,  G5,
  A5, FS5, G5,  A5, G5,  B5, A5,  G5, 
  
  FS5, E5, FS5, E5, D5, E5,  FS5, G5, 
  A5,  B5, G5,  B5, A5, B5,  CS6, D6, 
  A5,  B5, CS6, D6, E6, FS6, G6,  A6
};

uint8_t beats[] = {
  2,  4,  4,  2,  4,  4,  4,  4,
  4,  4,  4,  4,  4,  4,  2,  4,
  4,  2,  4,  4,  4,  4,  4,  4,
  4,  4,  4,  4,  2,  4,  4,  2,
  4,  4,  4,  4,  4,  4,  4,  4,
  4,  4,  2,  4,  4,  2,  4,  4,
  4,  4,  4,  4,  4,  4,  4,  4
};

void setup() {
  pinMode (BUZZER, OUTPUT);
}
void loop() {
  for (uint8_t i = 0; i < 56 ; i++) {
    // note duration quarter note = 1000 / 4,
    // eighth note = 1000/8, etc.
    uint16_t dura = 1000 / beats[i];
    tone(BUZZER, chords[i], dura);
    // to distinguish notes. put duration between them.
    // note duration + 30% :
    uint16_t pause = dura * 1.30;
    delay(pause);
  }
}
