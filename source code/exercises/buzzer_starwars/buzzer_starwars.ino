#include "pitches.h"

uint8_t const BUZZER = A0;

uint16_t chords[] = {
  F4, GS4, F4, A4, C5, E5, 
  F4, GS4, F4, C5, A4, F4, C5, A4,
  
  A4, A4, A4, F4, C5, A4, F4, C5, A4,
  E5, E5, E5, F5, C5, GS4, F4, C5, A4,

  A5, A4, A4, A5, GS5, G5, FS5, F5,
  AS4, DS5, D5, CS4, C5, AS4, C5
  
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
  // put your setup code here, to run once:
  pinMode (BUZZER, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  for (uint8_t i = 0; i < 56 ; i++) {
    // note duration quarter note = 1000 / 4,
    //eighth note = 1000/8, etc.
    uint16_t dura = 1000 / beats[i];
    tone(BUZZER, chords[i], dura);
    // to distinguish notes. put duration between them.
    // note duration + 30% :
    uint16_t pause = dura * 1.30;
    delay(pause);
  }
}
