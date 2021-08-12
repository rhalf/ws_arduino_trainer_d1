#ifndef _WATCHDOG_H
#define _WATCHDOG_H

#include "Arduino.h"
#include <avr/wdt.h>

/// @author Rhalf Wendel D Caacbay <rhalfcaacbay@gmail.com>

class WatchDog {

public:

// 15mS                           WDTO_15MS
// 30mS                           WDTO_30MS
// 60mS                           WDTO_60MS
// 120mS                          WDTO_120MS
// 250mS                          WDTO_250MS
// 500mS                          WDTO_500MS
// 1S                             WDTO_1S            
// 2S                             WDTO_2S
// 4S                             WDTO_4S
// 8S                             WDTO_8S

static const uint8_t M015 = WDTO_15MS;
static const uint8_t M030 = WDTO_30MS;
static const uint8_t M060 = WDTO_60MS;
static const uint8_t M120 = WDTO_120MS;
static const uint8_t M250 = WDTO_250MS;
static const uint8_t M500 = WDTO_500MS;
static const uint8_t S001 = WDTO_1S;
static const uint8_t S002 = WDTO_2S;
static const uint8_t S004 = WDTO_4S;
static const uint8_t S008 = WDTO_8S;

static void disable(void);
static void enable(uint8_t interval);
static void reset(void);
private:


};
#endif // _WATCHDOG_H
