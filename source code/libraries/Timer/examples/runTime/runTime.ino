#include<Timer.h>

Timer timer0(Timer::MICROS);
Timer timer1(Timer::MILLIS);
Timer timer2(Timer::SECONDS);

void callback0() {
    Serial.println("Micros   : " + String( Timer::getMicros()));
}

void callback1() {
    Serial.println("Millis   : " + String( Timer::getMillis()));
}

void callback2() {
    Serial.println("Seconds  : " + String( Timer::getSeconds()));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("Welcome to Timer class..."));
  Serial.println(F("rhalfcaacbay@gmail.com"));

  timer0.begin(Timer::FOREVER, 1000000, callback0);
  timer1.begin(Timer::FOREVER, 1000, callback1);
  timer2.begin(Timer::FOREVER, 1, callback2);

  timer0.start();
  timer1.start();
  timer2.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  timer0.run();
  timer1.run();
  timer2.run();
}