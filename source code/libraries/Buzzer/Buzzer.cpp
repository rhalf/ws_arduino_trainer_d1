#include "Buzzer.h"
#include "Arduino.h"
// typedef void (* CallBack)();

Buzzer::Buzzer(uint8_t pin){
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

Buzzer::Buzzer(uint8_t pin, uint16_t frequency){
  _pin = pin;
   _frequency = frequency;
  pinMode(_pin, OUTPUT);
}

Buzzer::Buzzer(void){
  pinMode(_pin, OUTPUT);
}

void Buzzer::setFrequency(uint16_t frequency) {
  _frequency = frequency;
}

void Buzzer::setTime(uint16_t time) {
  _time = time;
}

void Buzzer::play() {
    tone(_pin, _frequency, _time);
}

void Buzzer::stop(void) {
   noTone(_pin);
}