#include "WatchDog.h"
#include "Arduino.h"
#include <avr/wdt.h>

// time before watchdog firing    argument of wdt_enable()
// -------------------------------------------------------
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

static void WatchDog::enable(uint8_t interval) {
  wdt_enable(interval);
}

//static void WatchDog::disable(void)  __attribute__((naked)) __attribute__((section(".init3")));
static void WatchDog::disable()  {  wdt_reset(); MCUSR = 0; wdt_disable();}

static void WatchDog::reset()  { wdt_reset(); }