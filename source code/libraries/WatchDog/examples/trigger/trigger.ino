#include<WatchDog.h>

void setup() {
  // put your setup code here, to run once:
  // this library disables watchDog every startup to prevent restarting again
  // M015 = 015ms
  // M030 = 030ms
  // M060 = 060ms
  // M120 = 120ms
  // M250 = 250ms
  // M500 = 500ms
  // S001 = 001s
  // S002 = 002s
  // S004 = 004s
  // S008 = 008s

  Serial.begin(9600);
  Serial.println(F("Welcome to WatchDog Library"));
  WatchDog::enable(WatchDog::S002);
}

void loop() {
  // put your main code here, to run repeatedly:
  WatchDog::reset();
  // infite loop can trigger watchDog
  // create this infinite loop to immitate hanging.
  // if WatchDog::reset() were not called within enabled set time
  // WatchDog will trigger device cpu hard reset
  while(true) { }
  Serial.println(F("Unreachable code..."));

}