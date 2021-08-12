#ifndef _BUZZER_H
#define _BUZZER_H

#include "Arduino.h"

/// @author Rhalf Wendel D Caacbay <rhalfcaacbay@gmail.com>
//typedef void (* CallBack)();

class Buzzer {

public:
  Buzzer();
  Buzzer(uint8_t pin);
  Buzzer(uint8_t pin, uint16_t frequency);

  void setFrequency(uint16_t frequency);
  void setTime(uint16_t time);

  void play(void);
  void stop(void);

private:
  uint8_t _pin = 13;
  uint8_t _type = 0;

  uint16_t _frequency = 1875;
  uint16_t _time = 50;

};
#endif // _BUZZER_H
