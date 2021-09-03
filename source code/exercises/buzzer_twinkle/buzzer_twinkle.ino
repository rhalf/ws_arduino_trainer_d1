#include "pitches.h"

uint8_t const BUZZER = A0;

uint16_t chords[] = {
  C4, C4, G4, G4, A4, A4, G4,
  F4, F4, E4, E4, D4, D4, C4,
  G4, G4, F4, F4, E4, E4, D4, 
  G4, G4, F4, F4, E4, E4, D4,
  C4, C4, G4, G4, A4, A4, G4,
  F4, F4, E4, E4, D4, D4, C4,
};

uint8_t beats[] = {
  1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 
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

