#include "pitches.h"

uint8_t const BUZZER = A0;

//Mario main theme melody
uint16_t chords[] = {
  E7, E7, 0, E7,
  0, C7, E7, 0,
  G7, 0, 0,  0,
  G6, 0, 0, 0,

  C7, 0, 0, G6,
  0, 0, E6, 0,
  0, A6, 0, B6,
  0, AS6, A6, 0,

  G6, E7, G7,
  A7, 0, F7, G7,
  0, E7, 0, C7,
  D7, B6, 0, 0,

  C7, 0, 0, G6,
  0, 0, E6, 0,
  0, A6, 0, B6,
  0, AS6, A6, 0,

  G6, E7, G7,
  A7, 0, F7, G7,
  0, E7, 0, C7,
  D7, B6, 0, 0
};

//Mario main them tempo
uint8_t beats[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

//Underworld melody
//uint16_t chords[] = {
//  C4, C5, A3, A4,
//  AS3, AS4, 0,
//  0,
//  C4, C5, A3, A4,
//  AS3, AS4, 0,
//  0,
//  F3, F4, D3, D4,
//  DS3, DS4, 0,
//  0,
//  F3, F4, D3, D4,
//  DS3, DS4, 0,
//  0, DS4, CS4, D4,
//  CS4, DS4,
//  DS4, GS3,
//  G3, CS4,
//  C4, FS4, F4, E3, AS4, A4,
//  GS4, DS4, B3,
//  AS3, A3, GS3,
//  0, 0, 0
//};
//
////Underwolrd tempo
//uint8_t beats[] = {
//  12, 12, 12, 12,
//  12, 12, 6,
//  3,
//  12, 12, 12, 12,
//  12, 12, 6,
//  3,
//  12, 12, 12, 12,
//  12, 12, 6,
//  3,
//  12, 12, 12, 12,
//  12, 12, 6,
//  6, 18, 18, 18,
//  6, 6,
//  6, 6,
//  6, 6,
//  18, 18, 18, 18, 18, 18,
//  10, 10, 10,
//  10, 10, 10,
//  3, 3, 3
//};

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
